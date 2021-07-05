/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoon <hyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 19:55:45 by hyoon             #+#    #+#             */
/*   Updated: 2021/07/05 14:13:29 by hyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstack.h"

t_stack	*new(int content)
{
	t_stack	*n;

	n = (t_stack *)malloc(sizeof(t_stack));
	if (n == NULL)
		return (NULL);
	n->content = content;
	n->prev = NULL;
	n->next = NULL;
	return (n);
}
