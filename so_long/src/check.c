/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:45:31 by donshin           #+#    #+#             */
/*   Updated: 2022/03/29 00:28:51 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_component_cnt(t_game *game)
{
	if (game->map_comp.num_player_spon != 1)
		error_exit("Spon site must be one.");
	if (game->map_comp.num_collections == 0)
		error_exit("Collection must be exist.");
	if (game->map_comp.portal_list.next == 0)
		error_exit("Portal must be exist.");
}

void	check_map_rectangle(t_game *game)
{
	int	iter;

	iter = 0;
	while (iter < game->map_info.row)
		if ((int)ft_strlen(game->map_info.map[iter++]) != game->map_info.col)
			error_exit("Map must be rectangle.");
}

void	check_map_surrounded(t_game *game)
{
	int	row;
	int	col;

	row = 0;
	while (row < game->map_info.row)
	{
		col = 0;
		while (col < game->map_info.col)
		{
			if (row == 0 || row == game->map_info.row - 1)
			{
				if (game->map_info.map[row][col] != '1')
					error_exit("Map must be surrounded by wall.");
			}
			else if (col == 0 || col == game->map_info.col - 1)
			{
				if (game->map_info.map[row][col] != '1')
					error_exit("Map must be surrounded by wall.");
			}
			col++;
		}
		row++;
	}
}

void	check_map_comp(char c)
{
	if (!ft_strchr("10PCE", (int)c))
		error_exit("Invalid map component.");
}
