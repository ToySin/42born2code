/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:41:33 by donshin           #+#    #+#             */
/*   Updated: 2022/03/22 16:35:18 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	free_comp(t_game *game)
{
	t_collection	*c_temp;
	t_portal		*p_temp;

	while (game->map_comp.collection_list.next)
	{
		c_temp = game->map_comp.collection_list.next;
		game->map_comp.collection_list.next =
				c_temp->next;
		free(c_temp);
	}
	while (game->map_comp.portal_list.next)
	{
		p_temp = game->map_comp.portal_list.next;
		game->map_comp.portal_list.next =
				p_temp->next;
		free(p_temp);
	}
}

static void	free_asset(t_game *game)
{
	free(game->assets.collection_img);
	free(game->assets.player_img);
	free(game->assets.portal_img);
	free(game->assets.tile_img);
	free(game->assets.wall_img);
}

void	error_exit(char *msg)
{
	ft_putendl_fd("Error", 1);
	ft_putendl_fd(msg, 1);
	exit(1);
}

int	close_exit(t_game *game)
{
	free_asset(game);
	free_comp(game);
	exit(0);
}
