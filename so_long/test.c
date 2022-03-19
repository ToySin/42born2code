#include "include/so_long.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_game	game;
	int		fd;

	if (argc != 2)
		error_exit("Correct usage: ./so_long [MAP_FILE].ber");

	init_game(&game, argv[1]);
	draw_map(&game);
	mlx_loop(game.mlx);
}

void	ft_put_img64(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img, x * BLOCK_SIZE, y * BLOCK_SIZE);
}

void	error_exit(char *msg)
{
	ft_putendl_fd("Error", 1);
	ft_putendl_fd(msg, 1);
	exit(1);
}

int	open_file(char *file_path)
{
	int	fd;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		error_exit("File open fail.\nCheck file path.\n");
	return (fd);
}

char	**read_file(int fd)
{
	char	**result;
	char	*line;
	char	*save;
	char	*temp;

	save = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		temp = ft_strjoin(save, line);
		if (!temp)
			error_exit("Map read fail.\n");
		free(save);
		save = temp;
	}
	result = ft_split(save, '\n');
	return (result);
}

void	get_map_size(t_game *game)
{
	char	**map;
	int		row;
	int		col;

	map = game->map_info.map;
	row = 0;
	while (map[row])
		row++;
	col = ft_strlen(map[0]);
	game->map_info.row = row;
	game->map_info.col = col;
}

void	get_map_component(t_game *game)
{
	t_list	*node;
	char	**map;
	int		row;
	int		col;

	map = game->map_info.map;
	row = 0;
	while (row < game->map_info.row)
	{
		col = 0;
		while (col < game->map_info.col)
		{
			if (map[row][col] == 'P')
				game->map_comp.num_player_spon++;
			else if (map[row][col] == 'C')
			{
				ft_lstadd_back(&(game->map_comp.collection_list),
						ft_lstnew(get_collection_node(col, row)));
			}
			else if (map[row][col] == 'E')
			{
				ft_lstadd_back(&(game->map_comp.portal_list),
						ft_lstnew(get_portal_node(col, row)));
			}
			col++;
		}
		row++;
	}
}

void	init_map(t_game *game, char *file_path)
{
	int	fd;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		error_exit("Bla Bla");
	game->map_info.map = read_file(fd);
	if (!game->map_info.map)
		error_exit("Bla Bla");
	get_map_size(game);
	get_map_component(game);
}

void	init_win(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx,
			game->map_info.col * BLOCK_SIZE,
			game->map_info.row * BLOCK_SIZE, "so_long");
}

void	init_img(t_game *game)
{
	int	img_size;

	img_size = 64;
	game->assets.collection_img =
			mlx_xpm_file_to_image(game->mlx,
			"asset/collection.xpm", &img_size, &img_size);
	game->assets.portal_img =
			mlx_xpm_file_to_image(game->mlx,
			"asset/portal.xpm", &img_size, &img_size);
	game->assets.player_img =
			mlx_xpm_file_to_image(game->mlx,
			"asset/player.xpm", &img_size, &img_size);
	game->assets.tile_img =
			mlx_xpm_file_to_image(game->mlx,
			"asset/tile.xpm", &img_size, &img_size);
	game->assets.wall_img =
			mlx_xpm_file_to_image(game->mlx,
			"asset/wall.xpm", &img_size, &img_size);
}

void	init_game(t_game *game, char *file_path)
{
	init_map(game, file_path);
	init_win(game);
	init_img(game);
}

void	draw_map(t_game *game)
{
	int	row;
	int	col;

	row = 0;
	while (row < game->map_info.row)
	{
		col = 0;
		while (col < game->map_info.col)
		{
			ft_put_img64(game, game->assets.tile_img, col, row);
			if (game->map_info.map[row][col] == '1')
				ft_put_img64(game, game->assets.wall_img, col, row);
			col++;
		}
		row++;
	}
}

void	draw_component(t_game *game)
{

}
