/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 23:51:09 by donshin           #+#    #+#             */
/*   Updated: 2022/05/02 01:03:05 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_struct.h"

t_node	*pop_front(t_deque *deque)
{
	t_node	*result;

	if (!deque->size)
		return 0;
	result = deque->header->next;
	result->prev->next = result->next;
	result->next->prev = result->prev;
	result->prev = 0;
	result->next = 0;
	deque->size--;
	return (result);
}

t_node	*pop_back(t_deque *deque)
{
	t_node	*result;

	if (!deque->size)
		return 0;
	result = deque->trailer->prev;
	result->prev->next = result->next;
	result->next->prev = result->prev;
	result->prev = 0;
	result->next = 0;
	deque->size--;
	return (result);
}

void	*push_front(t_deque *deque, t_node *node)
{
	node->prev = deque->header;
	node->next = deque->header->next;
	deque->header->next->prev = node;
	deque->header->next = node;
	deque->size++;
}

void	*push_back(t_deque *deque, t_node *node)
{
	node->prev = deque->trailer->prev;
	node->next = deque->trailer;
	deque->trailer->prev->next = node;
	deque->trailer->prev = node;
	deque->size++;
}
