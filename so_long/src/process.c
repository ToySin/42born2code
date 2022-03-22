/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:31:02 by donshin           #+#    #+#             */
/*   Updated: 2022/03/22 15:33:03 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static t_collection	*find_collection_node(t_game *game)
{
	int	player_x;
	int	player_y;
	t_collection	*node;

	player_x = game->player.pos.x;
	player_y = game->player.pos.y;
	node = game->map_comp.collection_list.next;
	while (node)
	{
		if (node->pos.x == player_x && node->pos.y == player_y)
			return (node);
		node = node->next;
	}
	return (0);
}

static t_portal	*find_portal_node(t_game *game)
{
	int	player_x;
	int	player_y;
	t_portal	*node;

	player_x = game->player.pos.x;
	player_y = game->player.pos.y;
	node = game->map_comp.portal_list.next;
	while (node)
	{
		if (node->pos.x == player_x && node->pos.y == player_y)
			return (node);
		node = node->next;
	}
	return (0);
}

void	collect_process(t_game *game)
{
	if (find_collection_node(game))
		game->player.num_collected++;
	if (game->player.num_collected == game->map_comp.num_collections)
		game->player.is_have_key = 1;
}

void	portal_process(t_game *game)
{
	if (find_portal_node(game) && game->player.is_have_key)
		exit(0); // game done
}
