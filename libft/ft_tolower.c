/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-la-p <bde-la-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:54:26 by bde-la-p          #+#    #+#             */
/*   Updated: 2025/04/28 13:56:46 by bde-la-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	else
		return (c);
}
/*
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	char	test;

	test = 'a';
	printf("%c", tolower(test));
	printf("%c", ft_tolower(test));
}*/
