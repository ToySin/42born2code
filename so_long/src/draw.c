/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:25:09 by donshin           #+#    #+#             */
/*   Updated: 2022/03/29 00:21:13 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	draw_map(t_game *game)
{
	int	row;
	int	col;

	row = 0;
	while (row < game->map_info.row)
	{
		col = 0;
		while (col < game->map_info.col)
		{
			ft_put_img64(game, game->assets.tile_img, col, row);
			if (game->map_info.map[row][col] == '1')
				ft_put_img64(game, game->assets.wall_img, col, row);
			col++;
		}
		row++;
	}
}

void	draw_collection(t_game *game)
{
	t_collection	*i_node;

	i_node = game->map_comp.collection_list.next;
	while (i_node)
	{
		ft_put_img64(game, game->assets.collection_img,
				i_node->pos.x, i_node->pos.y);
		i_node = i_node->next;
	}
}

void	draw_portal(t_game *game)
{
	t_portal	*i_node;

	i_node = game->map_comp.portal_list.next;
	while (i_node)
	{
		ft_put_img64(game, game->assets.portal_img,
				i_node->pos.x, i_node->pos.y);
		i_node = i_node->next;
	}
}

void	draw_player(t_game *game)
{
	ft_put_img64(game, game->assets.player_img,
		game->player.pos.x, game->player.pos.y);
}
