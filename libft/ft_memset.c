/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-la-p <bde-la-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 13:58:07 by bde-la-p          #+#    #+#             */
/*   Updated: 2025/04/28 14:42:02 by bde-la-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*tmp;

	i = 0;
	tmp = s;
	while (i < n)
	{
		tmp[i] = c;
		i++;
	}
	return (s);
}
/*
#include <stdio.h>

int	main(void)
{
	char	src[] = "Bonsoir";
	int	value;
	size_t	nb;

	value = '6';
	nb = 4;
	ft_memset(src, value, nb);
	printf("%s", src);
	return(0);
}*/
