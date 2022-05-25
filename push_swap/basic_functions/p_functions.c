/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_functions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:28:41 by donshin           #+#    #+#             */
/*   Updated: 2022/05/24 12:31:19 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_deque *a, t_deque *b)
{
	if (b->size > 0)
	{
		push_front(a, pop_front(b));
	}
}

void	pb(t_deque *a, t_deque *b)
{
	if (a->size > 0)
	{
		push_front(b, pop_front(a));
	}
}
