/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 19:55:41 by donshin           #+#    #+#             */
/*   Updated: 2022/05/02 01:03:09 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_STRUCT_H
# define MY_STRUCT_H

typedef struct s_node
{
	int				elem;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_deque
{
	t_node	*header;
	t_node	*trailer;
	int		size;
}	t_deque;

t_deque	*get_deque();
t_node	*get_node(int elem);

t_node	*pop_front(t_deque *deque);
t_node	*pop_back(t_deque *deque);
void	*push_front(t_deque *deque, t_node *node);
void	*push_back(t_deque *deque, t_node *node);




#endif
