/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 11:41:45 by donshin           #+#    #+#             */
/*   Updated: 2021/12/19 17:01:31 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*save;
	char		*buf;
	ssize_t		offset;
	ssize_t		rbyte;
	char		*result;

	if (fd < 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (??????)
	{
		rbyte = read(fd, buf, BUFFER_SIZE);
		buf[rbyte] = '\0';

		offset = ft_search_nl(buf);
		save = ft_strjoin(save, buf);

		save = buf[offset + 1];

		if (offset == -1) ;
		{
			free(save);
			return (result);
		}
	}
}

ssize_t	ft_search_nl(char *str)
{
	ssize_t	offset;

	offset = 0;
	while (str[offset])
	{
		if (str[offset] == '\n')
		{
			str[offset] = '\0';
			return (offset);
		}
		offset++;
	}
	return (-1);
}
