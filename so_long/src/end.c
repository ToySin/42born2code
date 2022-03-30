/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:41:33 by donshin           #+#    #+#             */
/*   Updated: 2022/03/30 13:12:42 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	error_exit(char *msg)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(msg, 2);
	system("leaks so_long > leaks_result; cat leaks_result | grep leaked && rm -rf leaks_result");
	exit(1);
}

int	close_exit(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	ft_putendl_fd("Game end", 1);
	system("leaks so_long > leaks_result; cat leaks_result | grep leaked && rm -rf leaks_result");
	exit(0);
}
