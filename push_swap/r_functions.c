/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_functions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:40:57 by donshin           #+#    #+#             */
/*   Updated: 2022/05/24 12:31:19 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_deque *a)
{
	push_back(a, pop_front(a));
}

void	rb(t_deque *b)
{
	push_back(b, pop_front(b));
}

void	rr(t_deque *a, t_deque *b)
{
	ra(a);
	rb(b);
}
