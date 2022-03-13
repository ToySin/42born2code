#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_game	game;

	if (argc != 2)
		error_exit("Correct Usage: ./so_long [MAP_FILE].ber");
	fd = open_file(argv[1]);

	// map read

	// mlx window ~~~
}
