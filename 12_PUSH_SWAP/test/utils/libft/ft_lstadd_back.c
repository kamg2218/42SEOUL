/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 02:06:09 by hyoon             #+#    #+#             */
/*   Updated: 2020/04/11 02:06:11 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*l;

	l = *lst;
	if (!new)
		return ;
	else if (!l)
	{
		*lst = new;
		return ;
	}
	while (l->next)
		l = l->next;
	l->next = new;
	new->next = NULL;
}
