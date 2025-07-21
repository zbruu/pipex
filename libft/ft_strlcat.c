/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-la-p <bde-la-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:05:34 by bde-la-p          #+#    #+#             */
/*   Updated: 2025/05/02 14:20:22 by bde-la-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;
	size_t	j;

	dest_len = 0;
	while (dest[dest_len] != '\0' && dest_len < size)
		dest_len++;
	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	if (dest_len == size)
		return (size + src_len);
	i = 0;
	j = dest_len;
	while (src[i] != '\0' && j + 1 < size)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest_len + src_len);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	dest[] = "jour";
	char	src[] = "nuit";
	size_t	size = 8;

	ft_strlcat(dest, src, size);
	printf("%s", dest);
}*/
