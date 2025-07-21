/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-la-p <bde-la-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:37:56 by bde-la-p          #+#    #+#             */
/*   Updated: 2025/04/29 15:35:48 by bde-la-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	const char	*tmp_src;
	char		*tmp_dest;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	tmp_src = src;
	tmp_dest = dest;
	while (i < n)
	{
		tmp_dest[i] = tmp_src[i];
		i++;
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	src[] = "Carrement";
	char	dest[] = "yes";
	size_t	nb;

	nb = 2;
	ft_memcpy(dest, src, nb);
	printf("Fonction maison : %s\n", dest);
}*/
