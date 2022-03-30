/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:29:41 by donshin           #+#    #+#             */
/*   Updated: 2022/03/30 16:59:40 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

#include <stdio.h>

int	open_file(char *file_path)
{
	int		fd;
	char	*suffix;

	suffix = ft_substr(file_path, ft_strlen(file_path) - 4, 4);
	if (ft_strncmp(".ber", suffix, 4))
		error_exit("Invalid suffix");
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		error_exit("Failed to open file.");
	free(suffix);
	return (fd);
}

char	**read_file(int fd)
{
	char	**result;
	char	*line;
	char	*save;
	char	*temp;

	save = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		temp = ft_strjoin(save, line);
		free(line);
		if (!temp)
			error_exit("Map read fail.");
		free(save);
		save = temp;
	}
	result = ft_split(save, '\n');
	free(save);
	if (!result[0])
		error_exit("Map read fail.emp");
	return (result);
}
