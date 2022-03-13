#include <stdio.h>
#include <stdlib.h>
#include "mlx_beta/mlx.h"

#define X_EVENT_KEY_PRESS 2
#define X_EVENT_KEY_EXIT 17

# define KEY_R 15
# define KEY_ESC 63

# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13

# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126

# define ONE_BLOCK 64

# define UP 0
# define DOWN 1
# define LEFT 2
# define RIGHT 3

const static int	g_coordinates_x[4] = {0, 0, -1, 1};
const static int	g_coordinates_y[4] = {-1, 1, 0, 0};

typedef struct player
{
	int x;
	int y;
	int cnt;

	void *mlx;
	void *win;
	void *img;
}t_player;

void	init(t_player *player)
{
	int	width1 = 64;
	int height1 = 64;

	player->x = 64;
	player->y = 64;
	player->cnt = 0;

	player->mlx = mlx_init();
	player->win = mlx_new_window(player->mlx, 640, 640, "donshin");
	player->img = mlx_xpm_file_to_image(player->mlx, "asset/player_front.xpm",
			&width1, &height1);
}

int		is_collision(t_player *player, int x, int y)
{
	return (0);
}

void	move_dir(t_player *player, int dir)
{
	int target_x;
	int target_y;

	target_x = player->x + ONE_BLOCK * g_coordinates_x[dir];
	target_y = player->y + ONE_BLOCK * g_coordinates_y[dir];

	if (!is_collision(player, target_x, target_y))
	{
		player->x = target_x;
		player->y = target_y;
		player->cnt++;
	}
}

int		key_press(int keycode, t_player *player)
{
	if (keycode == KEY_ESC)
		exit(0);
	else if (keycode == KEY_W)
	{
		player->x += ONE_BLOCK * g_coordinates_x[UP];
		player->y += ONE_BLOCK * g_coordinates_y[UP];
		player->cnt++;
	}
	else if (keycode == KEY_S)
	{
		player->x += ONE_BLOCK * g_coordinates_x[DOWN];
		player->y += ONE_BLOCK * g_coordinates_y[DOWN];
		player->cnt++;
	}
	else if (keycode == KEY_A)
	{
		player->x += ONE_BLOCK * g_coordinates_x[LEFT];
		player->y += ONE_BLOCK * g_coordinates_y[LEFT];
		player->cnt++;
	}
	else if (keycode == KEY_D)
	{
		player->x += ONE_BLOCK * g_coordinates_x[RIGHT];
		player->y += ONE_BLOCK * g_coordinates_y[RIGHT];
		player->cnt++;
	}
	mlx_clear_window(player->mlx, player->win);
	mlx_put_image_to_window(player->mlx, player->win, player->img, player->x, player->y);
	printf("Move cnt: %d\n", player->cnt);
	return (0);
}

int main()
{
	t_player	player;

	init(&player);

	mlx_hook(player.win, X_EVENT_KEY_PRESS, 0, key_press, &player);
	mlx_loop(player.mlx);

	return (0);
}
