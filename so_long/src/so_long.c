/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:44:45 by donshin           #+#    #+#             */
/*   Updated: 2022/03/29 12:43:23 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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

	system("leaks so_long > leaks_result; cat leaks_result | grep leaked && rm -rf leaks_result");

	mlx_hook(game.win, ON_KEYDOWN, 0, &key_press, &game);
	mlx_hook(game.win, ON_DESTROY, 0, &close_exit, &game);

	system("leaks so_long > leaks_result; cat leaks_result | grep leaked && rm -rf leaks_result");

	mlx_loop(game.mlx);
}
