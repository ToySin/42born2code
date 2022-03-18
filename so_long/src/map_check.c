/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 19:58:50 by donshin           #+#    #+#             */
/*   Updated: 2022/03/18 11:39:37 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_map_square(t_game *game)
{
	int	line_cnt;
	int	line_width;

	line_cnt = 0;
	while (line_cnt < game->map_info.height)
	{
		line_width = ft_strlen(game->map_info.map[line_cnt++]);
		if (line_width != game->map_info.width)
			error_exit("Wrong map file(not square)\n");
	}
}

void	check_map_surrounded(t_game *game)
{
	int	row;
	int	col;

	row = 0;
	while (row < game->map_info.height)
	{
		if (game->map_info.map[row][0] != '1')
			error_exit("Wrong map file(not surrounded by wall)\n");
		if (game->map_info.map[row][game->map_info.width - 1] != '1')
			error_exit("Wrong map file(not surrounded by wall)\n");
		if ((row == 0) && (row == game->map_info.height - 1))
		{
			col = 1;
			while (col < game->map_info.width - 1)
				if (game->map_info.map[row][col++] != '1')
					error_exit("Wrong map file(not surrounded by wall)\n");
		}
	}
}

void	check_map_component(t_game *game)
{

}
