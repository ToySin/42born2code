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

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%c", game.map_info.map[i][j]);
		}
		
	}

	// mlx window ~~~
}
