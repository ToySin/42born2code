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

	if (fd < 2 || OPEN_MAX < fd || BUFFER_SIZE < 1)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	offset = -1;
	while (offset == -1)
	{
		offset = read(fd, buf, BUFFER_SIZE);
		if (offset < 1)
		{
			if (!offset)
				offset = -1;
			break ;
		}
		buf[offset] = '\0';
		save = ft_string_adder(save, buf);
		offset = ft_search_and_set_nl(save);
	}
	return (ft_linetrim(save, buf, offset));
}

ssize_t	ft_search_and_set_nl(char *str)
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

char	*ft_string_adder(char *save, char *buf)
{
	char	*result;

	if (save)
		result = ft_strjoin(save, buf);
	else
		result = ft_strjoin("\0", buf);
	free(save);
	return (result);
}

char	*ft_linetrim(char *save, char *buf, sszie_t offset)
{
	char	*trimed;
	char	*tmp;

	trimed = NULL;
	if (save)
	{
		trimed = ft_strjoin(save, "\0");
		tmp = NULL;
		if (offset != -1)
			tmp = ft_strjoin(save + offset + 1, "\0");
		free(save);
		save = tmp;
	}
	free(buf);
	buf = NULL;
	return (trimed);
}
