#include "../include/so_long.h"

void	move_dir(t_game *game, int dir)
{
	int	target_x;
	int	target_y;

	target_x = game->player_info.pos_x + g_coordinates_x[dir];
	target_y = game->player_info.pos_y + g_coordinates_y[dir];

	//if (is_collision(game->map_info, target_x, target_y)) return ;
	game->player_info.pos_x = target_x;
	game->player_info.pos_y = target_y;
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