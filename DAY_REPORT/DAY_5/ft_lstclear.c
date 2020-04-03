/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 19:55:18 by marvin            #+#    #+#             */
/*   Updated: 2020/02/29 19:55:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_lstclear(t_list **lst, void (*del)(void *))
{
    t_list  *L;
    t_list  *front;

    L = *lst;
    if (!L)
        return  ;
    while (L->next)
    {
        front = L;
        L = L->next;
        del(front->content);
        free(front);
    }
    del(L->content);
    free(L);
    *lst = NULL;
}