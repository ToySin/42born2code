/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:19:23 by donshin           #+#    #+#             */
/*   Updated: 2022/03/17 19:46:50 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef struct s_game t_game;

void	check_map_square(t_game *game);
void	check_map_surrounded(t_game *game);
void	check_map_component(t_game *game);

#endif
