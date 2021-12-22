/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 11:41:45 by donshin           #+#    #+#             */
/*   Updated: 2021/12/22 23:02:47 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_offset_nl(char *s);
static char		*ft_string_adder(char *save, char *buf, int mode);
static char		*ft_linetrim(char *save, char *buf);

char	*get_next_line(int fd)
{
	static char	*save;
	char		*buf;
	ssize_t		rbyte;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	rbyte = 1;
	while (rbyte && (!save || !ft_strchr(save, '\n')))
	{
		rbyte = read(fd, buf, BUFFER_SIZE);
		if (rbyte == -1)
		{
			free(save);
			free(buf);
			save = NULL;
			return (NULL);
		}
		buf[rbyte] = '\0';
		save = ft_string_adder(save, buf, 1);
	}
	buf = ft_linetrim(save, buf);
	save = ft_string_adder(save, buf, 0);
	return (buf);
}

static size_t	ft_offset_nl(char *s)
{
	size_t	offset;

	offset = 0;
	while (s[offset])
	{
		if (s[offset] == '\n')
			return (offset);
		offset++;
	}
	return (offset);
}

static char	*ft_string_adder(char *save, char *buf, int mode)
{
	char	*tmp;
	size_t	offset;

	if (mode && (*buf))
	{
		if (save)
			tmp = ft_strjoin(save, buf);
		else
			tmp = ft_strjoin("", buf);
		free(save);
		return (tmp);
	}
	else
	{
		offset = ft_offset_nl(save);
		tmp = ft_strjoin(save + offset + 1, "");
		free(save);
		return (tmp);
	}
}

static char	*ft_linetrim(char *save, char *buf)
{
	size_t	offset;
	char	*trimed;

	free(buf);
	if (!(*save))
		return (NULL);
	offset = ft_offset_nl(save);
	trimed = ft_substr(save, 0, offset + 1);
	return (trimed);
}
