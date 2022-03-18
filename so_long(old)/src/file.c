/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 22:00:58 by donshin           #+#    #+#             */
/*   Updated: 2022/03/17 17:16:08 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	open_file(char *file_path)
{
	int	fd;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		error_exit("File open fail!(Wrong file name)\n");
	return (fd);
}

char	**read_file(int fd)
{
	char	**result;
	char	*line;
	char	*save;
	char	*temp;

	save = ft_strdup("");
	if (!save)
		error_exit("Map read fail!(Memory allocation)\n");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		temp = ft_strjoin(save, line);
		if (!temp)
			error_exit("Map read fail!(Memory allocation)\n");
		free(save);
		save = temp;
	}
	result = ft_split(save, '\n');
	if (!result)
		error_exit("Map read fail!(Memory allocation)\n");
	free(save);
	return (result);
}
