/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:13:15 by donshin           #+#    #+#             */
/*   Updated: 2022/04/11 15:51:33 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_node
{
	int				elem;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_deque
{
	int		size;
	t_node	*head;
	t_node	*tail;
}	t_deque;

t_node	*get_node(int elem);
void	insert_node(t_deque *s, int elem);

void	sa(t_deque *s_a);
void	sb(t_deque *s_b);
void	ss(t_deque *s_a, t_deque *s_b);
void	pa(t_deque *s_a, t_deque *s_b);
void	pb(t_deque *s_a, t_deque *s_b);
void	ra(t_deque *s_a);
void	rb(t_deque *s_b);
void	rr(t_deque *s_a, t_deque *s_b);
void	rra(t_deque *s_a);
void	rrb(t_deque *s_b);
void	rrr(t_deque *s_a, t_deque *s_b);

#endif
