/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 21:51:13 by donshin           #+#    #+#             */
/*   Updated: 2022/03/16 16:43:12 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

typedef struct s_game t_game;

void	draw_map(t_game *game);
void	draw_player(t_game *game);
void	draw_collections(t_game *game);
void	draw_exit(t_game *game);

#endif
