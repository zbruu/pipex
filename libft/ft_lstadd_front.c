/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-la-p <bde-la-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:19:03 by bde-la-p          #+#    #+#             */
/*   Updated: 2025/05/05 12:25:39 by bde-la-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst != NULL && new != NULL)
	{
		new->next = *lst;
		*lst = new;
	}
}
/* On verifie que les deux pointeurs ne sont pas nuls.
 * On relie le champ 'next' de new a l'actuel premier element.
 * On met a jour la tete de liste pour qu`elle pointe sur new.
 * Le debut de la liste est maintenant l'element new.*/
