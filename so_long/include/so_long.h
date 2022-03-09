#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>

# include "error.h"
# include "file.h"

# include "../lib/include/libft.h"
# include "../lib/include/get_next_line.h"
# include "../mlx_beta/mlx.h"

typedef struct	s_img
{
	char	*img_path;
	int		width;
	int		height;
}				t_img;

typedef struct s_map
{

	t_img	wall_img;
	t_img	back_img;
	t_img	player_img;
	t_img	collection_img;
	t_img	exit_img;
}				t_map;

#endif
