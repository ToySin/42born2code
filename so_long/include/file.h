#ifndef FILE_H
# define FILE_H

typedef struct s_game t_game;

int		open_file(char *file_path);

void	player_img_load(t_game *param);
void	map_img_load(t_game *param);

#endif
