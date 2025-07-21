/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-la-p <bde-la-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 12:58:12 by bde-la-p          #+#    #+#             */
/*   Updated: 2025/07/16 14:41:03 by bde-la-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h> // for malloc and free
# include <unistd.h> // for pipe, fork, write, read
# include <stdio.h> // for perror and printf for tests
# include <sys/wait.h> // for wait and/or waitpid
# include <fcntl.h> // for open()
# include "../libft/libft.h"

typedef struct s_pipex_data
{
	int		fd[2];
	char	**cmd_args;
	char	*path;
}	t_pipex_data;

//Sub-functions
char				*get_path(char *cmd, char **envp);
char				**get_cmd_args(char *str);

//get_cmd_args utils
int					skip_spaces(char *str, int i);
int					count_args(char *str);
int					get_arg_len(char *str, int i);
int					get_arg_end(char *str, int start);
char				*copy_arg(char *str, int *i);

//handle_erros_and_frees
void				exit_with_error(const char *msg, int code,
						t_pipex_data *data);
void				free_cmd_path(t_pipex_data *data);
//pipex utils
int					open_input_file(char *filename, t_pipex_data *data);
int					open_output_file(char *filename, t_pipex_data *data);
void				free_close_fds(t_pipex_data *data);
void				check_path(t_pipex_data *data);

#endif
