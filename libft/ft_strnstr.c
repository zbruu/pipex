/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-la-p <bde-la-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 17:24:15 by bde-la-p          #+#    #+#             */
/*   Updated: 2025/04/29 19:49:43 by bde-la-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t ln)
{
	size_t	i;
	size_t	j;

	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] != '\0' && i < ln)
	{
		j = 0;
		while (little[j] != '\0' && big[i + j] != '\0'
			&& (i + j) < ln && big[i + j] == little[j])
			j++;
		if (little[j] == '\0')
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>

int	main(void)
{
	const char	big[] = "je te souhaite une bonne soiree";
	const char	little[] = "souhaite";
	size_t			len;

	len = 19;
	printf("%s", ft_strnstr(big, little, len));
}*/
