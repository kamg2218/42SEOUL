/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 19:55:31 by marvin            #+#    #+#             */
/*   Updated: 2020/02/29 19:55:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int     ft_count(t_list *lst)
{
    int     count;
    
    count = 1;
    if (!lst)
        return (0);
    while (lst->next)
    {
        count++;
        lst = lst->next;
    }
    return (count);    
}
t_list  *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list  *new;
    int     count;

    count = ft_count(lst);
    new = (t_list *)malloc(sizeof(t_list) * count);
    if (new == NULL)
        return (0);
	if (!lst)
	{
		new = NULL;
		return (new);
	}
    count = 0;
    while (lst->next)
    {
        new[count].content = f(lst->content);
		new[count].next = &new[count + 1];
 		del(lst->content);
        lst = lst->next;
        count++;
	}
	new[count].content = f(lst->content);
	new[count].next = NULL;
    return (new);
}