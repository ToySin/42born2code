/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:46:37 by donshin           #+#    #+#             */
/*   Updated: 2022/03/30 11:21:57 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

const static int	g_coordinates_x[4] = {0, 0, -1, 1};
const static int	g_coordinates_y[4] = {-1, 1, 0, 0};

static void	move_dir(t_game *game, int dir)
{
	int	target_x;
	int	target_y;

	target_x = game->player.pos.x + g_coordinates_x[dir];
	target_y = game->player.pos.y + g_coordinates_y[dir];
	if (is_collision(game, target_x, target_y))
		return ;
	draw_tile_at_player(game);
	game->player.pos.x = target_x;
	game->player.pos.y = target_y;
	draw_tile_at_player(game);
	collect_process(game);
	portal_process(game);
	footprint_process(game);
	draw_portal(game);
	draw_player(game);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_exit(game);
	else if (keycode == KEY_W)
		move_dir(game, UP);
	else if (keycode == KEY_A)
		move_dir(game, LEFT);
	else if (keycode == KEY_S)
		move_dir(game, DOWN);
	else if (keycode == KEY_D)
		move_dir(game, RIGHT);
	return (0);
}
