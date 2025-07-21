/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_args_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-la-p <bde-la-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 18:16:55 by bde-la-p          #+#    #+#             */
/*   Updated: 2025/07/02 17:30:14 by bde-la-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

/*Skips over all tabs and spacesstarting at index i in str
Returns the index pf the next non-space character.*/
int	skip_spaces(char *str, int i)
{
	while (str[i] && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i++;
	return (i);
}

/*Counts how many arguments are in str, treating anything inside quotes as
one argument. Handles both single and double quotes to correctly group words.*/
int	count_args(char *str)
{
	int (i) = 0;
	int (count) = 0;
	int (in_quote) = 0;
	char (quote_char) = 0;
	while (str[i])
	{
		i = skip_spaces(str, i);
		if (!str[i])
			break ;
		count++;
		while (str[i] && (in_quote || !(str[i] == ' '
					|| (str[i] >= 9 && str[i] <= 13))))
		{
			if (!in_quote && (str[i] == '\'' || str[i] == '"'))
			{
				in_quote = 1;
				quote_char = str[i];
			}
			else if (in_quote && str[i] == quote_char)
				in_quote = 0;
			i++;
		}
	}
	return (count);
}

/*Returns the length of the next argument, starting from index i,
counting inside quotes as part of the argument. Useful for malloc.*/
int	get_arg_len(char *str, int i)
{
	int		len;
	int		in_quote;
	char	quote_char;

	len = 0;
	in_quote = 0;
	quote_char = 0;
	while (str[i] && (in_quote || !(str[i] == ' '
				|| (str[i] >= 9 && str[i] <= 13))))
	{
		if (!in_quote && (str[i] == '\'' || str[i] == '"'))
		{
			in_quote = 1;
			quote_char = str[i];
		}
		else if (in_quote && str[i] == quote_char)
			in_quote = 0;
		len++;
		i++;
	}
	return (len);
}

/*Finds the index immediately after the end of the next argument (handles
quoted strings). Lets you know where the argument stops so you can slice it.*/
int	get_arg_end(char *str, int start)
{
	int		i;
	int		in_quote;
	char	quote_char;

	i = start;
	in_quote = 0;
	quote_char = 0;
	while (str[i] && (in_quote
			|| !(str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))))
	{
		if (!in_quote && (str[i] == '\'' || str[i] == '"'))
		{
			in_quote = 1;
			quote_char = str[i];
		}
		else if (in_quote && str[i] == quote_char)
			in_quote = 0;
		i++;
	}
	return (i);
}

/*Allocates and copies the next argument into a new string, starting from
index i, including auotes content. Returns a malloc'd string ready to be
added to your arguments array.*/
char	*copy_arg(char *str, int *i)
{
	int		start;
	int		end;
	char	*arg;
	int		j;

	*i = skip_spaces(str, *i);
	start = *i;
	end = get_arg_end(str, start);
	arg = malloc(sizeof(char) * (end - start + 1));
	if (!arg)
		return (NULL);
	j = 0;
	while (start < end)
	{
		arg[j] = str[start];
		j++;
		start++;
	}
	arg[j] = '\0';
	*i = end;
	return (arg);
}
/*
int	main(int ac, char **av)
{
	int	i;

	i = 2;
	(void)ac;
	printf("%s\n", av[i]);
	printf("Count args : %d\n", count_args(av[i]));
	printf("Arg length : %d\n", get_arg_len(av[i], 0));
	printf("Copy : %s\n", copy_arg(av[i], 1));
}*/