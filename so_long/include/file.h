/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 22:00:56 by donshin           #+#    #+#             */
/*   Updated: 2022/03/14 14:24:43 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H

typedef struct s_game t_game;

int		open_file(char *file_path);
char	**read_map(int fd);

void	player_img_load(t_game *param);
void	map_img_load(t_game *param);

#endif
