/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 12:30:20 by donshin           #+#    #+#             */
/*   Updated: 2022/05/24 20:05:24 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_deque *a)
{
	push_front(a, pop_back(a));
}

void	rrb(t_deque *b)
{
	push_front(b, pop_back(b));
}

void	rrr(t_deque *a, t_deque *b)
{
	rra(a);
	rrb(b);
}
