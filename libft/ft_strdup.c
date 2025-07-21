/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-la-p <bde-la-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:56:42 by bde-la-p          #+#    #+#             */
/*   Updated: 2025/05/05 16:14:50 by bde-la-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdlib.h>
#include <stdio.h>
*/
#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		len;
	char	*dup;

	len = 0;
	while (src[len] != '\0')
		len++;
	dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	len = 0;
	while (src[len] != '\0')
	{
		dup[len] = src[len];
		len++;
	}
	dup[len] = '\0';
	return (dup);
}
/*
int	main(void)
{
	char	word[] = "gnee";

	printf("%s", ft_strdup(word));
}*/
