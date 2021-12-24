/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 13:27:59 by donshin           #+#    #+#             */
/*   Updated: 2021/12/24 16:31:46 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_string_adder(char *save, char *buf);
static char	*ft_line_with_nl(char **save, char *buf, char *nl_ptr);
static char	*ft_treat_last(char **save, char *buf, ssize_t rbyte);

char	*get_next_line(int fd)
{
	static char	*save[OPEN_MAX];
	ssize_t		rbyte;
	char		*buf;
	char		*nl_ptr;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	rbyte = read(fd, buf, BUFFER_SIZE);
	while (rbyte > 0)
	{
		buf[rbyte];
		save[fd] = ft_string_adder(save[fd], buf);
		nl_ptr = ft_strchr(save[fd], '\n');
		if (nl_ptr)
			return (ft_line_with_nl(&save[fd], buf, nl_ptr));
		rbyte = read(fd, buf, BUFFER_SIZE);
	}
	return (ft_treat_last(&save[fd], buf, rbyte));
}

static char	*ft_string_adder(char *save, char *buf)
{
	char	*comb;

	if (!save)
		comb = ft_strdup(buf);
	else
		comb = ft_strjoin(save, buf);
	free(save);
	return (comb);
}

static char *ft_line_with_nl(char **save, char *buf, char *nl_ptr)
{
	char	*line;
	char	*tmp;

	line = (char *)malloc(sizeof(char) * (nl_ptr - *save + 2));
	if (!line)
		return (NULL);
	ft_strlcpy(line, *save, nl_ptr - *save + 2);
	tmp = ft_strdup(nl_ptr + 1);
	free(*save);
	*save = tmp;
	return (line);
}

static char	*ft_treat_last(char **save, char *buf, ssize_t rbyte)
{
	char *remain;

	free(buf);
	remain = NULL;
	if (!rbyte)
		remain = ft_strdup(*save);
	free(*save);
	return (remain);
}
