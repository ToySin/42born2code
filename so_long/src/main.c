#include "../include/so_long.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		fd;
	t_game	game;

	if (argc != 2)
		error_exit("Correct Usage: ./so_long [MAP_FILE].ber");
	fd = open_file(argv[1]);

	// map read
	game.map_info.map = read_map(fd);

	// map check


	// init game
	//  img load
	//  mlx init
	player_img_load(&game);
	map_img_load(&game);

	// mlx window ~~~
}
