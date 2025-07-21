/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-la-p <bde-la-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 13:26:08 by bde-la-p          #+#    #+#             */
/*   Updated: 2025/07/17 13:59:59 by bde-la-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

/* Prototype reminder : int dup2(int oldfd, int newfd); */

static int	child(int *fd, char **av, char **envp)
{
	t_pipex_data	data;
	int				infile;

	data.fd[0] = fd[0];
	data.fd[1] = fd[1];
	data.cmd_args = NULL;
	data.path = NULL;
	close(data.fd[0]);
	infile = open_input_file(av[1], &data);
	data.cmd_args = get_cmd_args(av[2]);
	if (!data.cmd_args || !data.cmd_args[0] || data.cmd_args[0][0] == '\0')
		exit_with_error("get_cmd_args", 127, &data);
	data.path = get_path(data.cmd_args[0], envp);
	if (!data.path)
		check_path(&data);
	if (dup2(infile, STDIN_FILENO) < 0 || dup2(data.fd[1], STDOUT_FILENO) < 0)
		exit_with_error("dup2 child", 1, &data);
	close(infile);
	close(data.fd[1]);
	execve(data.path, data.cmd_args, envp);
	exit_with_error("execve child", 126, &data);
	return (1);
}

static int	parent(int *fd, char **av, char **envp)
{
	t_pipex_data	data;
	int				outfile;

	data.fd[0] = fd[0];
	data.fd[1] = fd[1];
	data.cmd_args = NULL;
	data.path = NULL;
	close(data.fd[1]);
	outfile = open_output_file(av[4], &data);
	data.cmd_args = get_cmd_args(av[3]);
	if (!data.cmd_args || !data.cmd_args[0] || data.cmd_args[0][0] == '\0')
		exit_with_error("get_cmd_args", 127, &data);
	data.path = get_path(data.cmd_args[0], envp);
	if (!data.path)
		check_path(&data);
	if (dup2(data.fd[0], STDIN_FILENO) < 0 || dup2(outfile, STDOUT_FILENO) < 0)
		exit_with_error("dup2 parent", 1, &data);
	close(data.fd[0]);
	close(outfile);
	execve(data.path, data.cmd_args, envp);
	exit_with_error("execve parent", 126, &data);
	return (1);
}

static int	setup_pipe_and_fork(int *fd, int *pid)
{
	if (pipe(fd) == -1)
	{
		perror("pipe");
		return (1);
	}
	*pid = fork();
	if (*pid == -1)
	{
		perror("fork");
		return (2);
	}
	return (0);
}

int	main(int ac, char **av, char **envp)
{
	int				fd[2];
	int				pid;

	if (ac != 5)
	{
		write(2, "Error - Usage: ./pipex file1 cmd1 cmd2 file2\n", 45);
		return (1);
	}
	if (setup_pipe_and_fork(fd, &pid))
		return (1);
	if (pid == 0)
		child(fd, av, envp);
	else
	{
		waitpid(pid, NULL, 0);
		parent(fd, av, envp);
	}
	return (0);
}
