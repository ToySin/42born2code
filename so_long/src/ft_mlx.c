/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 12:49:51 by donshin           #+#    #+#             */
/*   Updated: 2022/03/18 13:40:20 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

const static char	*asset_path = "../asset/";

void	*ft_mlx_load_img(t_game *game, char *file_name)
{
	char	*file_path;
	void	*img;
	int		img_size = 64;

	file_path = ft_strjoin(asset_path, file_name);
	img = mlx_xpm_file_to_image(game->mlx, file_path, &img_size, &img_size);
	if (!img)
		error_exit("Xpm file to image fail.\n Check file path and name.\n");
	free(file_path);
	return (img);
}

void	ft_put_img64(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img,
			x * BLOCK_SIZE, y * BLOCK_SIZE);
}