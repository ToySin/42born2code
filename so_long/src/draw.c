/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 09:44:54 by donshin           #+#    #+#             */
/*   Updated: 2022/03/16 17:46:48 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	draw_map(t_game *game)
{
	int	width;
	int	height;

	height = 0;
	while (height < game->map_info.height)
	{
		width = 0;
		while (width < game->map_info.width)
		{
			
			mlx_put_image_to_window(game->mlx, game->win,
					game->map_info.background_img, height * 64, width * 64);
			printf("passed!!!\n");
			if (game->map_info.map[height][width] == '1')
				mlx_put_image_to_window(game->mlx, game->win,
						game->map_info.wall_img, height * 64, width * 64);
			width++;
		}
		height++;
	}
}
