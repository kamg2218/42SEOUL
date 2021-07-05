/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 19:55:37 by hyoon             #+#    #+#             */
/*   Updated: 2021/07/05 14:11:54 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstack.h"

void	pop(t_stack **head)
{
	t_stack		*tmp;

	if (head == NULL || *head == NULL)
		return ;
	tmp = *head;
	*head = (*head)->next;
	if (tmp == *head)
		*head = NULL;
	else
	{
		tmp->prev->next = *head;
		(*head)->prev = tmp->prev;
	}
	free(tmp);
}
