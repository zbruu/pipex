/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path_and_cmd_args.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-la-p <bde-la-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:51:35 by bde-la-p          #+#    #+#             */
/*   Updated: 2025/07/16 14:54:28 by bde-la-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

/* GET_CMD_ARGS PRINCIPAL FUNCTION (see it sub-functions in utils file)-------*/
char	**get_cmd_args(char *str)
{
	int		count;
	char	**args;

	int (i) = 0;
	int (j) = 0;
	count = count_args(str);
	args = malloc(sizeof(char *) * (count + 1));
	if (!args)
		return (NULL);
	while (str[i] && j < count)
	{
		i = skip_spaces(str, i);
		args[j] = copy_arg(str, &i);
		if (!args[j])
		{
			while (j > 0)
				free(args[--j]);
			free(args);
			return (NULL);
		}
		j++;
	}
	args[j] = NULL;
	return (args);
}
/*----------------------------------------------------------------------------*/

/*BEGINNING OF GET_PATH FUNCTION*/

static void	free_split(char **splitted)
{
	int		i;

	i = 0;
	if (!splitted)
		return ;
	while (splitted[i])
	{
		free(splitted[i]);
		i++;
	}
	free(splitted);
}

// needs ft_strlen and ft_memcpy from libft
static char	*join_path_cmd(char *path, char *cmd)
{
	char	*full;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(path);
	len2 = ft_strlen(cmd);
	full = malloc(len1 + 1 + len2 + 1);
	if (!full)
		return (NULL);
	ft_memcpy(full, path, len1);
	full[len1] = '/';
	ft_memcpy(full + len1 + 1, cmd, len2);
	full[len1 + 1 + len2] = '\0';
	return (full);
}

static char	*search_in_paths(char **paths, char *cmd)
{
	int		i;
	char	*candidate;

	i = 0;
	while (paths[i])
	{
		candidate = join_path_cmd(paths[i], cmd);
		if (candidate == NULL)
		{
			i++;
			continue ;
		}
		if (access(candidate, X_OK) == 0)
		{
			free_split(paths);
			return (candidate);
		}
		free(candidate);
		i++;
	}
	free_split(paths);
	return (NULL);
}

// needs ft_strncmp and ft_split from libft
char	*get_path(char *cmd, char **envp)
{
	int		i;
	char	*path_line;
	char	**paths;

	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, X_OK) == 0)
			return (ft_strdup(cmd));
		else
			return (NULL);
	}
	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	if (!envp[i])
		return (NULL);
	path_line = envp[i] + 5;
	paths = ft_split(path_line, ':');
	if (!paths)
		return (NULL);
	return (search_in_paths(paths, cmd));
}

/* Main to test the get_cmd_args function*/
/*
int		main(int ac, char **av)
{
    char    **args;
    int     i;

    if (ac != 2)
    {
        printf("Usage: %s \"command with args\"\n", av[0]);
        return (1);
    }
    args = get_cmd_args(av[1]);
    if (!args)
    {
        printf("Error: get_cmd_args returned NULL\n");
        return (1);
    }
    i = 0;
    while (args[i])
    {
        printf("Arg[%d] = [%s]\n", i, args[i]);
        free(args[i]);
        i++;
    }
    free(args);
    return (0);
} */
