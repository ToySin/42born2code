/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 00:53:51 by donshin           #+#    #+#             */
/*   Updated: 2022/05/02 01:03:08 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_deque	*get_deque()
{
	t_deque	*deque;

	deque = malloc(sizeof(t_deque));
	deque->header = get_node(0);
	deque->trailer = get_node(0);
	deque->header->next = deque->trailer;
	deque->trailer->prev = deque->header;
	deque->size = 0;
	return (deque);
}

t_node	*get_node(int elem)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	node->elem = elem;
	node->prev = 0;
	node->next = 0;
	return (node);
}
