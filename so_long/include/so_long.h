#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>

#include <stdio.h>

# include "key.h"
# include "player.h"
# include "error.h"
# include "file.h"
# include "draw.h"
# include "init.h"
# include "map.h"

# include "../lib/include/libft.h"
# include "../lib/include/get_next_line.h"
# include "../mlx_beta/mlx.h"

# define BLOCK_SIZE 64

typedef struct s_player
{
	int		pos_x;
	int		pos_y;
	void	*front_img;
	void	*back_img;
	void	*left_img;
	void	*right_img;
}			t_player;

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
	void	*wall_img;
	void	*background_img;
	void	*collection_img;
	void	*exit_img;
}				t_map;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_player	player_info;
	t_map		map_info;
}				t_game;

#endif
