#include "include/so_long.h"
#include <stdio.h>

int	close_game(t_game *game)
{
	free(game->assets.collection_img);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_game	game;
	int		fd;

	if (argc != 2)
		error_exit("Correct usage: ./so_long [MAP_FILE].ber");

	init_game(&game, argv[1]);
	draw_map(&game);
	draw_component(&game);
	draw_player(&game);

	mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, &key_press, &game);
	mlx_hook(game.win, X_EVENT_KEY_EXIT, 0, &close_game, &game);
	mlx_loop(game.mlx);
}

static t_collection	*get_collection_node(int x, int y)
{
	t_collection	*node;

	node = malloc(sizeof(t_collection));
	if (!node)
		error_exit("Memory allocation fail\n");
	node->pos.x = x;
	node->pos.y = y;
	node->is_collected = 0;
	return (node);
}

static t_portal	*get_portal_node(int x, int y)
{
	t_portal	*node;

	node = malloc(sizeof(t_portal));
	if (!node)
		error_exit("Memory allocation fail\n");
	node->pos.x = x;
	node->pos.y = y;
	return (node);
}

void	ft_put_img64(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img,
			x * BLOCK_SIZE, y * BLOCK_SIZE);
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
				add_collection(game, col, row);
			else if (map[row][col] == 'E')
				add_portal(game, col, row);
			col++;
		}
		row++;
	}
}

void	get_player_spon_site(t_game *game)
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
			{
				game->player.pos.x = col;
				game->player.pos.y = row;
				return ;
			}
			col++;
		}
		row++;
	}
}

void	add_collection(t_game *game, int x, int y)
{
	t_collection	*node;

	node = get_collection_node(x, y);
	node->next = game->map_comp.collection_list.next;
	game->map_comp.collection_list.next = node;
}

void	add_portal(t_game *game, int x, int y)
{
	t_portal	*node;

	node = get_portal_node(x, y);
	node->next = game->map_comp.portal_list.next;
	game->map_comp.portal_list.next = node;
}

void	init_map(t_game *game, char *file_path)
{
	int	fd;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		error_exit("Failed to open file.\n");
	game->map_info.map = read_file(fd);
	if (!game->map_info.map)
		error_exit("Failed to read file.");
	get_map_size(game);
	get_map_component(game);
}

void	init_player(t_game *game)
{
	game->player.is_collect_all = 0;
	get_player_spon_site(game);
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

void	init_comp(t_game *game)
{
	game->map_comp.collection_list.next = 0;
	game->map_comp.portal_list.next = 0;
	game->map_comp.num_player_spon = 0;
}

void	init_game(t_game *game, char *file_path)
{
	init_comp(game);
	init_map(game, file_path);
	init_player(game);
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

static void	_draw_collection(t_game *game)
{
	t_collection	*i_node;

	i_node = game->map_comp.collection_list.next;
	while (i_node)
	{
		if (!(i_node->is_collected))
			ft_put_img64(game, game->assets.collection_img,
					i_node->pos.x, i_node->pos.y);
		i_node = i_node->next;
	}
}

static void	_draw_portal(t_game *game)
{
	t_portal	*i_node;

	i_node = game->map_comp.portal_list.next;
	while (i_node)
	{
		ft_put_img64(game, game->assets.portal_img,
				i_node->pos.x, i_node->pos.y);
		i_node = i_node->next;
	}
}

void	draw_component(t_game *game)
{
	_draw_collection(game);
	_draw_portal(game);
}

void	draw_player(t_game *game)
{
	ft_put_img64(game, game->assets.player_img,
		game->player.pos.x, game->player.pos.y);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		exit(0);
	else if (keycode == KEY_W || keycode == KEY_UP)
		move_up(game);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		move_left(game);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move_down(game);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_right(game);
	else if (keycode == KEY_ESC)
		exit(0);
	return (0);
}

const static int	g_coordinates_x[4] = {0, 0, -1, 1};
const static int	g_coordinates_y[4] = {-1, 1, 0, 0};

int	is_collision(t_game *game, int x, int y)
{
	return (game->map_info.map[y][x] == '1');
}

static t_collection	*find_collection_node(t_game *game)
{
	int	player_x;
	int	player_y;
	t_collection	*node;
	
	player_x = game->player.pos.x;
	player_y = game->player.pos.y;
	node = game->map_comp.collection_list.next;
	while (node)
	{
		if (node->pos.x == player_x && node->pos.y == player_y)
		{
			node->is_collected = 1;
			return (node);
		}
		node = node->next;
	}
	return (0);
}

static void	collect_process(t_game *game)
{
	t_collection	*node;

	node = find_collection_node(game);
	if (node)
	{
		
	}
}

void	move_dir(t_game *game, int dir)
{
	int	target_x;
	int	target_y;

	target_x = game->player.pos.x + g_coordinates_x[dir];
	target_y = game->player.pos.y + g_coordinates_y[dir];

	if (is_collision(game, target_x, target_y))
		return ;

	ft_put_img64(game, game->assets.tile_img,
			game->player.pos.x, game->player.pos.y);
	game->player.pos.x = target_x;
	game->player.pos.y = target_y;

	//collect process
	if (//collection locate)
		//collect

	if (game->player.is_collect_all)
		//game clear

	
	draw_player(game);
}

void	move_up(t_game *game)
{
	move_dir(game, UP);
}

void	move_down(t_game *game)
{
	move_dir(game, DOWN);
}

void	move_left(t_game *game)
{
	move_dir(game, LEFT);
}

void	move_right(t_game *game)
{
	move_dir(game, RIGHT);
}