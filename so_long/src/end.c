/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:41:33 by donshin           #+#    #+#             */
/*   Updated: 2022/03/22 15:49:52 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	error_exit(char *msg)
{
	ft_putendl_fd("Error", 1);
	ft_putendl_fd(msg, 1);
	exit(1);
}

int	close_exit(t_game *game)
{
	free(game->assets.collection_img);
	exit(0);
}
