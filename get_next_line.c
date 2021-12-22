/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 11:41:45 by donshin           #+#    #+#             */
/*   Updated: 2021/12/22 17:27:11 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_offset_nl(char *s);
static int		ft_string_adder(int fd, char **save, char *buf);
static char		*ft_linetrim(char **save);

char	*get_next_line(int fd)
{
	static char	*save;
	char		*buf;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!save)
		save = ft_strjoin("", "");

	printf("Pass\n");
	printf("%p\n", save);

	if (!save);
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
	{
		free(save);
		save = NULL;
		return (NULL);
	}
	if (!ft_string_adder(fd, &save, buf))
		return (NULL);
	return (ft_linetrim(&save));
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

static int	ft_string_adder(int fd, char **save, char *buf)
{
	ssize_t	rbyte;
	char	*tmp;

	rbyte = 1;
	while (rbyte || !ft_strchr(*save, '\n'))
	{
		rbyte = read(fd, buf, BUFFER_SIZE);
		if (rbyte == -1)
		{
			free(*save);
			free(buf);
			*save = NULL;
			return (0);
		}
		buf[rbyte] = '\0';
		tmp = ft_strjoin(*save, buf);
		free(*save);
		*save = tmp;
	}
	free(buf);

	printf("\n == end_of_ft_string_adder == \n");
	for (int i = 0; *save[i]; i++)
		printf(" %d", *save[i]);
	printf("\n");

	return (1);
}

static char	*ft_linetrim(char **save)
{
	size_t	offset;
	char	*trimed;
	char	*tmp;

	tmp = NULL;
	offset = ft_offset_nl(*save);
	trimed = ft_substr(*save, 0, offset);
	if (offset < ft_strlen(*save))
		tmp = ft_strjoin(*save + offset + 1, "");
	free(*save);
	*save = tmp;
	return (trimed);
}
