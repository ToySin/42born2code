/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:26:08 by donshin           #+#    #+#             */
/*   Updated: 2022/05/24 12:26:14 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_deque *a)
{
	t_node	*top_node;
	int		temp;

	if (a->size > 1)
	{
		top_node = a->header->next;
		temp = top_node->elem;
		top_node->elem = top_node->next->elem;
		top_node->next->elem = temp;
	}
}

void	sb(t_deque *b)
{
	t_node	*top_node;
	int		temp;

	if (b->size > 1)
	{
		top_node = b->header->next;
		temp = top_node->elem;
		top_node->elem = top_node->next->elem;
		top_node->next->elem = temp;
	}
}

void	ss(t_deque *a, t_deque *b)
{
	sa(a);
	sb(b);
}
