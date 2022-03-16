/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 09:44:54 by donshin           #+#    #+#             */
/*   Updated: 2022/03/16 09:51:15 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	draw_map(t_game *game)
{
	int	width;
	int	height;

	width = 0;
	height = 0;
	while (height < game->map_info.height)
	{
		while (width < game->map_info.width)
		{
			mlx_put_image_to_window(game->mlx, game->win,
					game->map_info.background_img, height * 64, width * 64);
			if (game->map_info.map[height][width] == "1")
				mlx_put_image_to_window(game->mlx, game->win,
						game->map_info.wall_img, height * 64, width * 64);
		}
	}
}
