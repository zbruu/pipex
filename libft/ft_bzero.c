/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-la-p <bde-la-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:00:26 by bde-la-p          #+#    #+#             */
/*   Updated: 2025/04/28 15:00:32 by bde-la-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*tmp;

	i = 0;
	tmp = s;
	while (i < n)
	{
		tmp[i] = '\0';
		i++;
	}
}
/*
#include <stdio.h>

int	main(void)
{
	char	str[] = "nouveau";
	size_t	nb;

	nb = 3;
	ft_bzero(str, nb);
}*/
