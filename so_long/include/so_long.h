/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:05:37 by donshin           #+#    #+#             */
/*   Updated: 2022/03/22 15:44:26 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>

# include "../lib/include/libft.h"
# include "../lib/include/get_next_line.h"
# include "../mlx_beta/mlx.h"

# define BLOCK_SIZE 64

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_EXIT 17

# define KEY_R 15
# define KEY_ESC 53

# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13

# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126

# define UP 0
# define DOWN 1
# define LEFT 2
# define RIGHT 3

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_collection
{
	t_pos				pos;
	int					is_collected;
	struct s_collection	*next;
}	t_collection;

typedef struct s_portal
{
	t_pos			pos;
	struct s_portal	*next;
}	t_portal;

typedef struct s_comp
{
	int				num_player_spon;
	int				num_collections;
	t_collection	collection_list;
	t_portal		portal_list;
}	t_comp;

typedef struct s_map
{
	char	**map;
	int		row;
	int		col;
}	t_map;

typedef struct s_asset
{
	void	*collection_img;
	void	*portal_img;
	void	*player_img;
	void	*tile_img;
	void	*wall_img;
}	t_asset;

typedef struct s_player
{
	t_pos	pos;
	int		num_collected;
	int		is_have_key;
	int		movement_cnt;
}	t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_map		map_info;
	t_comp		map_comp;
	t_asset		assets;
	t_player	player;
}	t_game;

void	*ft_load_img(t_game *game, char *file_path);
void	ft_put_img64(t_game *game, void *img, int x, int y);

void	error_exit(char *msg);
int		close_exit(t_game *game);

int		open_file(char *file_path);
char	**read_file(int fd);

void	get_map_size(t_game *game);
void	get_map_component(t_game *game);
void	get_player_spon_site(t_game *game);

void	add_collection(t_game *game, int x, int y);
void	add_portal(t_game *game, int x, int y);

void	collect_process(t_game *game);
void	portal_process(t_game *game);

void	init_map(t_game *game, char *file_path);
void	init_player(t_game *game);
void	init_win(t_game *game);
void	init_img(t_game *game);
void	init_comp(t_game *game);
void	init_game(t_game *game, char *file_path);

void	draw_map(t_game *game);
void	draw_collection(t_game *game);
void	draw_portal(t_game *game);
void	draw_player(t_game *game);

int		key_press(int keycode, t_game *game);

void	move_dir(t_game *game, int dir);
void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);

#endif
