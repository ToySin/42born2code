#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>

# include "key.h"
# include "error.h"
# include "file.h"

# include "../lib/include/libft.h"
# include "../lib/include/get_next_line.h"
# include "../mlx_beta/mlx.h"

typedef struct s_player
{
	int		pos_x;
	int		pos_y;
}			t_player;

typedef struct s_map
{
	char	**map;
	
	int		width;
	int		height;
}				t_map;

#endif
