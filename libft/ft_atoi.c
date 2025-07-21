/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-la-p <bde-la-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 17:59:45 by bde-la-p          #+#    #+#             */
/*   Updated: 2025/05/02 14:42:02 by bde-la-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	number;
	int	i;

	i = 0;
	sign = 1;
	number = 0;
	while ((nptr[i] <= 13 && nptr[i] >= 9) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	if (nptr[i] == '+' || nptr[i] == '-')
		return (0);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		number = number * 10 + (nptr[i] - '0');
		i++;
	}
	return (number * sign);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	const char	*n1;
	const char	*n2;
	const char	*n3;
	const char	*n4;

	n1 = "    -07";
	n2 = "    -+2048b56";
	n3 = "    --2048b56";
	n4 = "    +-2048b56";

	printf("%d\n", ft_atoi(n1));
	printf("%d\n", ft_atoi(n2));
	printf("%d\n", ft_atoi(n3));
	printf("%d\n", ft_atoi(n4));
	printf("------------------------------\n");
	printf("%d\n", atoi(n1));
        printf("%d\n", atoi(n2));
        printf("%d\n", atoi(n3));
        printf("%d\n", atoi(n4));
}*/
