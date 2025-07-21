/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-la-p <bde-la-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 11:12:58 by bde-la-p          #+#    #+#             */
/*   Updated: 2025/04/30 11:40:30 by bde-la-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
*/
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	size_t	total_size;
	char	*memory;

	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	total_size = nmemb * size;
	memory = malloc(total_size);
	if (memory == NULL)
		return (NULL);
	i = 0;
	while (i < total_size)
	{
		memory[i] = 0;
		i++;
	}
	return ((void *)memory);
}
/*
int	main(void)
{
	char	*rslt;
	size_t	i;
	size_t	count;
	
	i = 0;
	count = 12;
	rslt = ft_calloc(count, sizeof(int));
	if (rslt == NULL)
		printf("Echec");
	else
	{
		printf("Reussite");
		while (i < count)
		{
			printf("%d", rslt[i]);
			i++;
		}
	}
}*/
