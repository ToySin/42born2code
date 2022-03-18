/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:54:55 by donshin           #+#    #+#             */
/*   Updated: 2022/03/16 21:30:40 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_window(t_game *game)
{
	int	width;
	int	height;

	game->mlx = mlx_init();
	if (!game->mlx)
		error_exit("mlx_init() fail\n");
	width = game->map_info.width * BLOCK_SIZE;
	height = game->map_info.height * BLOCK_SIZE;
	game->win = mlx_new_window(game->mlx, width, height, "so_long");
	if (!game->win)
		error_exit("mlx_new_window() fail\n");
}

void	init_img(t_game *game)
{

}
