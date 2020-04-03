/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 19:55:10 by marvin            #+#    #+#             */
/*   Updated: 2020/02/29 19:55:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list  *L;

    L = *lst;
	if (!new)
		return	;
	else if (!L)
	{
		*lst = new;
		return	;
	}
    while (L->next)
    	L = L->next;
    L->next = new;
    new->next = NULL;
}