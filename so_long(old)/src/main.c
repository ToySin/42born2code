#include "../include/so_long.h"

int	main_loop(t_game *game)
{
	draw_map(game);
	return (0);
}

int	close_game(t_game *game)
{
	mlx_destroy_image(game->mlx, game->map_info.background_img);
	mlx_destroy_image(game->mlx, game->map_info.wall_img);
	mlx_destroy_image(game->mlx, game->map_info.collection_img);
	mlx_destroy_image(game->mlx, game->map_info.exit_img);
	mlx_destroy_image(game->mlx, game->player_info.back_img);
	mlx_destroy_window(game->mlx, game->win);
	return (0);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_game	game;

	if (argc != 2)
		error_exit("Correct Usage: ./so_long [MAP_FILE].ber");
	fd = open_file(argv[1]);

	// map read
	game.map_info.map = read_file(fd);
	game.map_info.height = 6;
	game.map_info.width = 5;

	// map check
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%c", game.map_info.map[i][j]);
		}
		printf("\n");
	}

	// init game
	//  img load
	player_img_load(&game);
	map_img_load(&game);

	//init mlx win
	init_window(&game);

	mlx_key_hook(game.win, &key_press, &game);
	printf("passed\n");

	mlx_loop_hook(game.mlx, &main_loop, &game);
	mlx_loop(game.mlx);
}
