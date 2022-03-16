#ifndef PLAYER_H
# define PLAYER_H

# define UP 0
# define DOWN 1
# define LEFT 2
# define RIGHT 3

const static int	g_coordinates_x[4] = {-1, 1, 0, 0};
const static int	g_coordinates_y[4] = {0, 0, -1, 1};

typedef struct s_game t_game;

void	move_dir(t_game *game, int direction);
void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);

#endif
