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

	if (fd < 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (read(fd, buf, BUFFER_SIZE) != -1)
	{
		offset = ft_search_nl(buf);
		if (offset == -1) ;
			// bla bla
		buf[offset] = '\0';
		 = ft_strjoin(save, buf);

		if (offset == BUFFER_SIZE) ;
			//buf 뒤에 남은거 없음
	}
}

ssize_t	ft_search_nl(char *str)
{
	ssize_t	offset;

	offset = 0;
	while (str[offset])
	{
		if (str[offset] == '\n')
			return (offset);
		offset++;
	}
	return (-1);
}
