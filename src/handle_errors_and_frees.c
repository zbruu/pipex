/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors_and_frees.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-la-p <bde-la-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 17:51:24 by bde-la-p          #+#    #+#             */
/*   Updated: 2025/07/17 13:23:34 by bde-la-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	free_cmd_path(t_pipex_data *data)
{
	int		i;

	if (data->cmd_args)
	{
		i = 0;
		while (data->cmd_args[i])
			free(data->cmd_args[i++]);
		free(data->cmd_args);
	}
	free(data->path);
}

void	exit_with_error(const char *msg, int code, t_pipex_data *data)
{
	close(data->fd[0]);
	close(data->fd[1]);
	free_cmd_path(data);
	if (code == 127)
	{
		write(2, "pipex: ", 7);
		write(2, msg, ft_strlen(msg));
		write(2, ": command not found\n", 20);
	}
	else
		perror(msg);
	exit(code);
}
