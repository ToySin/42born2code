/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:44:45 by donshin           #+#    #+#             */
/*   Updated: 2022/03/22 15:50:08 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		exit(0);
	else if (keycode == KEY_W || keycode == KEY_UP)
		move_up(game);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		move_left(game);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move_down(game);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_right(game);
	else if (keycode == KEY_ESC)
		exit(0);
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

	mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, &key_press, &game);
	mlx_hook(game.win, X_EVENT_KEY_EXIT, 0, &close_exit, &game);
	mlx_loop(game.mlx);
}
