/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 19:53:52 by hyoon             #+#    #+#             */
/*   Updated: 2021/07/05 14:12:46 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstack.h"

void	clear(t_stack **head)
{
	t_stack		*pre;
	t_stack		*tmp;

	if (head == NULL || *head == NULL)
		return ;
	tmp = *head;
	tmp->prev->next = NULL;
	while (tmp)
	{
		pre = tmp;
		tmp = tmp->next;
		free(pre);
	}
}
