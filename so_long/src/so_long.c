/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:44:45 by donshin           #+#    #+#             */
/*   Updated: 2022/03/29 00:14:14 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_exit();
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

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		error_exit("Correct usage: ./so_long [MAP_FILE].ber");

	init_game(&game, argv[1]);
	draw_map(&game);
	draw_collection(&game);
	draw_portal(&game);
	draw_player(&game);

	mlx_hook(game.win, ON_KEYDOWN, 0, &key_press, &game);
	mlx_hook(game.win, ON_DESTROY, 0, &close_exit, 0);
	mlx_loop(game.mlx);
}
