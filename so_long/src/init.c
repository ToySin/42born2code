/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:43:41 by donshin           #+#    #+#             */
/*   Updated: 2022/03/29 11:16:22 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	init_map(t_game *game, char *file_path)
{
	int	fd;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		error_exit("Failed to open file.");
	game->map_info.map = read_file(fd);
	if (!game->map_info.map)
		error_exit("Failed to read file.");
	get_map_size(game);
	get_map_component(game);
	check_component_cnt(game);
	check_map_rectangle(game);
	check_map_surrounded(game);
}

static void	init_player(t_game *game)
{
	game->player.num_collected = 0;
	game->player.is_have_key = 0;
	game->player.movement_cnt = 0;
	get_player_spon_site(game);
}

static void	init_win(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx,
			game->map_info.col * BLOCK_SIZE,
			game->map_info.row * BLOCK_SIZE, "so_long");
}

static void	init_img(t_game *game)
{
	game->assets.collection_img = ft_load_img(game, "./asset/collection.xpm");
	game->assets.portal_img = ft_load_img(game, "./asset/portal.xpm");
	game->assets.player_img = ft_load_img(game, "./asset/player.xpm");
	game->assets.tile_img = ft_load_img(game, "./asset/tile.xpm");
	game->assets.wall_img = ft_load_img(game, "./asset/wall.xpm");
}

void	init_game(t_game *game, char *file_path)
{
	init_map(game, file_path);
	init_player(game);
	init_win(game);
	init_img(game);
}
