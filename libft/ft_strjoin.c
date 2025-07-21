/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-la-p <bde-la-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:23:12 by bde-la-p          #+#    #+#             */
/*   Updated: 2025/05/05 16:11:10 by bde-la-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	fill_array(char *dest, const char *s1, const char *s2)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	len = i;
	i = 0;
	while (s2[i] != '\0')
	{
		dest[len + i] = s2[i];
		i ++;
	}
	dest[len + i] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		all_size;
	char		*result;

	if (s1 == NULL || s2 == NULL)
	{
		if (s1 != NULL)
			return (ft_strdup(s1));
		else if (s2 != NULL)
			return (ft_strdup(s2));
		else
			return (ft_strdup(""));
	}
	all_size = ft_strlen(s1) + ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * (all_size + 1));
	if (result == NULL)
		return (NULL);
	fill_array(result, s1, s2);
	return (result);
}
/*
#include <stdio.h>

int	main(void)
{
	char const	*s1 = "Bonjour";
	char const	*s2 = "Bonsoir";
	char	*result;

	result = ft_strjoin(s1, s2);
	printf("%s", result);
}*/
