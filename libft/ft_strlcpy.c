/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-la-p <bde-la-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:13:23 by bde-la-p          #+#    #+#             */
/*   Updated: 2025/04/28 18:24:13 by bde-la-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t siz)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (siz == 0)
	{
		while (src[i] != '\0')
			i++;
		return (i);
	}
	while (src[i] != '\0' && i < (siz - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	j = 0;
	while (src[j] != '\0')
		j++;
	return (j);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	ds[20];
	const char sr[] = "Hello, World!";
	size_t	size;

	size = 8;
	ft_strlcpy(ds, sr, size);
	printf("%s", ds);
	return (0);
}*/
