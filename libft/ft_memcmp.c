/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-la-p <bde-la-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:55:51 by bde-la-p          #+#    #+#             */
/*   Updated: 2025/04/29 16:06:02 by bde-la-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*s1bis;
	const unsigned char	*s2bis;

	if (n == 0)
		return (0);
	i = 0;
	s1bis = (const unsigned char *)s1;
	s2bis = (const unsigned char *)s2;
	while (i < n)
	{
		if (s1bis[i] != s2bis[i])
			return (s1bis[i] - s2bis[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	s1[] = "nulle";
	char	s2[] = "nunuche";
	size_t	n;

	n = 0;
	printf("Mine : %d\n", ft_memcmp(s1, s2, n));
	printf("Theirs : %d", memcmp(s1, s2, n));
}*/
