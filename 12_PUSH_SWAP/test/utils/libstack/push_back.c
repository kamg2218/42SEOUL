/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 19:54:51 by hyoon             #+#    #+#             */
/*   Updated: 2021/07/05 14:12:26 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstack.h"

t_stack	*push_back(t_stack **head, int content)
{
	t_stack		*n;

	if (head == NULL)
		return (NULL);
	n = new(content);
	if (n == NULL)
		return (NULL);
	if (*head == NULL)
	{
		*head = n;
		n->prev = n;
		n->next = n;
		return (n);
	}
	n->prev = (*head)->prev;
	n->next = *head;
	(*head)->prev->next = n;
	(*head)->prev = n;
	return (n);
}
