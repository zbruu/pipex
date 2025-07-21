/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-la-p <bde-la-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 18:18:31 by bde-la-p          #+#    #+#             */
/*   Updated: 2025/07/21 11:56:26 by bde-la-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

/*Opens a file in reading mode, leaves if error */
int	open_input_file(char *filename, t_pipex_data *data)
{
	int	infile;

	infile = open(filename, O_RDONLY);
	if (infile < 0)
		exit_with_error("open infile", 1, data);
	return (infile);
}

/* Opens a file in writing mode, leaves if error */
int	open_output_file(char *filename, t_pipex_data *data)
{
	int	outfile;

	outfile = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile < 0)
		exit_with_error("open outfile", 1, data);
	return (outfile);
}

/* Frees cmd_args and path, closes 2 fd */
void	free_close_fds(t_pipex_data *data)
{
	free_cmd_path(data);
	close(data->fd[0]);
	close(data->fd[1]);
}

/* Checks get_path, free/close if error */
void	check_path(t_pipex_data *data)
{
	if (!data->path)
	{
		write(2, *data->cmd_args, ft_strlen(data->cmd_args[0]));
		write(2, ": command not found\n", 20);
		free_close_fds(data);
		exit(127);
	}
}
