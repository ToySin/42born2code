/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:46:37 by donshin           #+#    #+#             */
/*   Updated: 2022/03/29 00:19:35 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

const static int	g_coordinates_x[4] = {0, 0, -1, 1};
const static int	g_coordinates_y[4] = {-1, 1, 0, 0};

void	move_dir(t_game *game, int dir)
{
	int	target_x;
	int	target_y;

	target_x = game->player.pos.x + g_coordinates_x[dir];
	target_y = game->player.pos.y + g_coordinates_y[dir];
	if (is_collision(game, target_x, target_y))
		return ;
	ft_put_img64(game, game->assets.tile_img,
			game->player.pos.x, game->player.pos.y);
	game->player.pos.x = target_x;
	game->player.pos.y = target_y;
	ft_put_img64(game, game->assets.tile_img,
			game->player.pos.x, game->player.pos.y);
	collect_process(game);
	portal_process(game);
	footprint_process(game);
	draw_portal(game);
	draw_player(game);
}