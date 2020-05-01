/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 02:06:36 by hyoon             #+#    #+#             */
/*   Updated: 2020/04/11 02:06:39 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*l;
	t_list	*front;

	l = *lst;
	while (l->next)
	{
		front = l;
		l = l->next;
		del(front->content);
		free(front);
	}
	del(l->content);
	free(l);
	*lst = NULL;
}
