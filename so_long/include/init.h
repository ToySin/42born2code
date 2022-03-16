/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 09:41:32 by donshin           #+#    #+#             */
/*   Updated: 2022/03/16 14:13:10 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

typedef struct s_game t_game;

void	init_window(t_game *game);

void	player_img_load(t_game *game);
void	map_img_load(t_game *game);

#endif
