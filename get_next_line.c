/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 13:27:59 by donshin           #+#    #+#             */
/*   Updated: 2021/12/26 18:32:09 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_string_adder(int fd, char *save);
static char	*ft_get_line(char *save);
static char	*ft_save_remain(char *save);

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	save = ft_string_adder(fd, save);
	if (!save)
		return (NULL);
	line = ft_get_line(save);
	save = ft_save_remain(save);
	return (line);
}

static char	*ft_string_adder(int fd, char *save)
{
	ssize_t	rbyte;
	char	*buf;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	rbyte = fd + 1;
	while (rbyte > 0 && !ft_my_strchr(save, '\n'))
	{
		rbyte = read(fd, buf, BUFFER_SIZE);
		if (rbyte == -1)
			break ;
		buf[rbyte] = '\0';
		save = ft_my_strjoin(save, buf);
	}
	free(buf);
	if (rbyte == -1)
		return (NULL);
	return (save);
}

static char	*ft_get_line(char *save)
{
	char	*line;
	char	*nl_ptr;

	if (*save == '\0')
		return (NULL);
	nl_ptr = ft_my_strchr(save, '\n');
	if (!nl_ptr)
		return (ft_strdup(save));
	line = (char *)malloc(sizeof(char) * (nl_ptr - save + 2));
	if (!line)
		return (NULL);
	ft_my_strlcpy(line, save, nl_ptr - save + 2);
	return (line);
}

static char	*ft_save_remain(char *save)
{
	char	*line;
	char	*nl_ptr;

	nl_ptr = ft_my_strchr(save, '\n');
	if (!nl_ptr)
	{
		free(save);
		return (NULL);
	}
	line = ft_strdup(nl_ptr + 1);
	free(save);
	return (line);
}
