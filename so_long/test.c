#include "include/so_long.h"
#include <stdio.h>

void	error_exit(char *msg);

int		open_file(char *file_path);
char	**read_file(int fd);

void	get_map_size(t_game *game);
void	get_map_component(t_game *game);

void	init_map(t_game *game, char *file_path);
void	init_win(t_game *game);
void	init_game(t_game *game, char *file_path);

int	main(int argc, char **argv)
{
	t_game	game;
	int		fd;

	if (argc != 2)
		error_exit("Correct usage: ./so_long [MAP_FILE].ber");

	init_game(&game, argv[1]);
	printf("row: %d, col: %d\n", game.map_info.row, game.map_info.col);
	mlx_loop(game.mlx);
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
				game->map_comp.num_collections++;
			else if (map[row][col] == 'E')
				game->map_comp.num_flag++;
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

void	init_game(t_game *game, char *file_path)
{
	init_map(game, file_path);
	init_win(game);
}
