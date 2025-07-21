/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-la-p <bde-la-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 14:45:21 by bde-la-p          #+#    #+#             */
/*   Updated: 2025/04/29 15:01:26 by bde-la-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*ss;

	i = 0;
	ss = (const unsigned char *)s;
	while (i < n)
	{
		if (ss[i] == (unsigned char)c)
			return ((void *)&ss[i]);
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>

int	 main(void)
{
	char	*str = "bien sur que oui";
	int		c;
	size_t		nb;
	char	*rslt;

	c = 'u';
	nb = 6;
	rslt = ft_memchr(str, c, nb);
	printf("%s", rslt);
}*/
