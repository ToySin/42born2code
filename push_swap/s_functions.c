/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_functions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:26:08 by donshin           #+#    #+#             */
/*   Updated: 2022/04/11 16:04:51 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_deque *s_a)
{
	int	temp;

	temp = s_a->head->elem;
	s_a->head->elem = s_a->head->next->elem;
	s_a->head->next->elem = temp;
}

void	sb(t_deque *s_b)
{
	int	temp;

	temp = s_b->top->elem;
	s_b->top->elem = s_b->top->next->elem;
	s_b->top->next->elem = temp;
}

void	ss(t_deque *s_a, t_deque *s_b)
{
	sa(s_a);
	sb(s_b);
}
