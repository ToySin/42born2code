/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 12:49:51 by donshin           #+#    #+#             */
/*   Updated: 2022/03/30 12:27:39 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	*ft_load_img(t_game *game, char *file_path)
{
	void	*img;
	int		img_size;

	img_size = 64;
	img = mlx_xpm_file_to_image(game->mlx, file_path, &img_size, &img_size);
	if (!img)
		error_exit("Xpm file to image fail.\n");
	return (img);
}

void	ft_put_img64(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img,
		x * BLOCK_SIZE, y * BLOCK_SIZE);
}
