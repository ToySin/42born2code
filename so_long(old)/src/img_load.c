/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:03:12 by donshin           #+#    #+#             */
/*   Updated: 2022/03/16 17:52:13 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int width = 64;
static int height = 64;

void	player_img_load(t_game *param)
{
	param->player_info.back_img =
			mlx_xpm_file_to_image(param->mlx, "../asset/player_back.xpm",
			&width, &height);
	param->player_info.front_img =
			mlx_xpm_file_to_image(param->mlx, "../asset/player_front.xpm",
			&width, &height);
	param->player_info.left_img =
			mlx_xpm_file_to_image(param->mlx, "../asset/player_left.xpm",
			&width, &height);
	param->player_info.right_img =
			mlx_xpm_file_to_image(param->mlx, "../asset/player_right.xpm",
			&width, &height);
}

void	map_img_load(t_game *param)
{
	param->map_info.background_img =
			mlx_xpm_file_to_image(param->mlx, "../asset/background.xpm",
			&width, &height);
	param->map_info.collection_img =
			mlx_xpm_file_to_image(param->mlx, "../asset/collection.xpm",
			&width, &height);
	param->map_info.exit_img =
			mlx_xpm_file_to_image(param->mlx, "../asset/exit.xpm",
			&width, &height);
	param->map_info.wall_img =
			mlx_xpm_file_to_image(param->mlx, "../asset/wall.xpm",
			&width, &height);
}
