/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 19:55:15 by hyoon             #+#    #+#             */
/*   Updated: 2021/07/05 14:12:36 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstack.h"

int	size(t_stack **head)
{
	int			count;
	t_stack		*tmp;

	if (head == NULL || *head == NULL)
		return (0);
	count = 1;
	tmp = *head;
	while (tmp->next != *head)
	{
		++count;
		tmp = tmp->next;
	}
	return (count);
}
