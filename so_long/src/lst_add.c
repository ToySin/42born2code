/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:34:49 by donshin           #+#    #+#             */
/*   Updated: 2022/03/29 10:11:42 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static t_collection	*get_collection_node(int x, int y)
{
	t_collection	*node;

	node = malloc(sizeof(t_collection));
	if (!node)
		error_exit("Memory allocation fail\n");
	node->pos.x = x;
	node->pos.y = y;
	node->is_collected = 0;
	return (node);
}

static t_portal	*get_portal_node(int x, int y)
{
	t_portal	*node;

	node = malloc(sizeof(t_portal));
	if (!node)
		error_exit("Memory allocation fail\n");
	node->pos.x = x;
	node->pos.y = y;
	return (node);
}

void	add_collection(t_game *game, int x, int y)
{
	t_collection	*node;

	node = get_collection_node(x, y);
	node->next = game->map_comp.collection_list.next;
	game->map_comp.collection_list.next = node;
	game->map_comp.num_collections++;
}

void	add_portal(t_game *game, int x, int y)
{
	t_portal	*node;

	node = get_portal_node(x, y);
	node->next = game->map_comp.portal_list.next;
	game->map_comp.portal_list.next = node;
}
