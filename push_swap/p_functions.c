/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_functions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:28:41 by donshin           #+#    #+#             */
/*   Updated: 2022/04/11 16:03:39 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_deque *s_a, t_deque *s_b)
{
	t_node	*node;

	if (!s_b->size)
		return ;
	node = s_b->top;
	s_b->top->prev->next = s_b->top->next;
	s_b->top->next->prev = s_b->top->prev;
	s_b->top = s_b->top->next;
	s_a->top->prev->next = node;
	s_a->top->prev = node;
	s_a->top = node;
	s_a->size++;
	s_b->size--;
}

void	pb(t_deque *s_a, t_deque *s_b)
{
	t_node	*node;

	node = s_a->top;
	s_a->top->prev->next = s_a->top->next;
	s_a->top->next->prev = s_a->top->prev;
	s_a->top = s_a->top->next;
	s_b->top->prev->next = node;
	s_b->top->prev = node;
	s_b->top = node;
}
