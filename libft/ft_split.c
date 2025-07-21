/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-la-p <bde-la-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 20:20:12 by bde-la-p          #+#    #+#             */
/*   Updated: 2025/05/02 14:49:04 by bde-la-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdlib.h>
#include <stdio.h>
*/
#include "libft.h"

/*Compte le nb de mots, c-a-d de sous-chaines separees par le delimiteur*/
static int	count_words(const char *s, char sep)
{
	int	i;
	int	count;
	int	in_word;

	i = 0;
	count = 0;
	in_word = 0;
	while (s[i] != '\0')
	{
		in_word = 0;
		while (s[i] == sep && s[i] != '\0')
			i++;
		while (s[i] != sep && s[i] != '\0')
		{
			if (in_word == 0)
			{
				count++;
				in_word = 1;
			}
			i++;
		}
	}
	return (count);
}

/*Safe memory allocation*/
static int	safe_malloc(char **final_result, int position, int buffer)
{
	int	i;

	i = 0;
	final_result[position] = malloc(buffer);
	if (final_result[position] == NULL)
	{
		while (i < position)
		{
			free(final_result[i++]);
		}
		free(final_result);
		return (1);
	}
	return (0);
}

/*Copie un mot depuis la chaine-source*/
static int	fill(char **final_result, char const *s, char sep)
{
	int	i;
	int	len;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		len = 0;
		while (s[i] == sep && s[i] != '\0')
			i++;
		while (s[i] != sep && s[i] != '\0')
		{
			len++;
			i++;
		}
		if (len > 0)
		{
			if (safe_malloc(final_result, j, len + 1) != 0)
				return (1);
			ft_strlcpy(final_result[j], &s[i - len], len + 1);
			j++;
		}
	}
	return (0);
}

/*Fonction principale*/
char	**ft_split(char const *s, char c)
{
	int		words;
	char	**final_result;

	if (s == NULL)
		return (NULL);
	words = 0;
	words = count_words(s, c);
	final_result = malloc(sizeof(char *) * (words + 1));
	if (final_result == NULL)
		return (NULL);
	final_result[words] = NULL;
	if (fill(final_result, s, c) != 0)
		return (NULL);
	return (final_result);
}
/*
int	main(void)
{
	char	*s = "  Comment ca va toi ?";
	char	**v = ft_split(s, ' ');

	while (*v)
		printf("%s\n", *v++);
}*/
