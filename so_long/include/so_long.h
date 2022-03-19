/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:05:37 by donshin           #+#    #+#             */
/*   Updated: 2022/03/19 18:42:41 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>

# include "../lib/include/libft.h"
# include "../lib/include/get_next_line.h"
# include "../mlx_beta/mlx.h"

# define BLOCK_SIZE 64

# define X_EVENT_KEY_EXIT 17

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_collection
{
	t_pos	pos;
	int		is_collected;
}	t_collection;

typedef struct s_portal
{
	t_pos	pos;
}	t_portal;

typedef struct s_comp
{
	int		num_player_spon;
	t_list	*collection_list;
	t_list	*portal_list;
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

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map	map_info;
	t_comp	map_comp;
	t_asset	assets;
}	t_game;

t_collection	*get_collection_node(int x, int y);
t_portal		*get_portal_node(int x, int y);


void	ft_put_img64(t_game *game, void *img, int x, int y);

void	error_exit(char *msg);

int		open_file(char *file_path);
char	**read_file(int fd);

void	get_map_size(t_game *game);
void	get_map_component(t_game *game); //컴포넌트를 구조체 방식으로 변경하기

void	init_map(t_game *game, char *file_path);
//void	init_player(t_game *game);
void	init_win(t_game *game);
void	init_img(t_game *game);
void	init_game(t_game *game, char *file_path);

void	draw_map(t_game *game);
void	draw_component(t_game *game);
void	draw_player(t_game *game);

#endif
