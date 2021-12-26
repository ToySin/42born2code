/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 22:23:10 by donshin           #+#    #+#             */
/*   Updated: 2021/12/26 22:51:55 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	char	*line;
	int		fd;
	int		i;

	fd = open("test.txt", O_RDONLY);
	fd = 0;
	printf("BUFFER_SIZE: %d\n", BUFFER_SIZE);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		i = 0;
		while (line[i])
			printf(" %d", line[i++]);
		printf("\n");
		printf("%s", line);
	}
	printf("This line is attached end of line\n");
	return (0);
}
