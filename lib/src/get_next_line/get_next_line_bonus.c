/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 13:27:59 by donshin           #+#    #+#             */
/*   Updated: 2022/03/01 18:01:16 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/get_next_line_bonus.h"

static t_save	*ft_find_fd(t_save *header, int fd);
static char		*ft_string_adder(int fd, char *save);
static char		*ft_get_line(char *save);
static char		*ft_save_remain(char *save, char **print_line);

char	*get_next_line(int fd)
{
	static t_save	lst_header;
	t_save			*fd_node;
	char			*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	fd_node = ft_find_fd(&lst_header, fd);
	if (!fd_node)
		return (0);
	fd_node->save = ft_string_adder(fd, fd_node->save);
	if (!fd_node->save)
	{
		ft_my_lstdelone(fd_node);
		return (0);
	}
	line = ft_get_line(fd_node->save);
	if (!line)
	{
		free(fd_node->save);
		ft_my_lstdelone(fd_node);
	}
	else
		fd_node->save = ft_save_remain(fd_node->save, &line);
	return (line);
}

static t_save	*ft_find_fd(t_save *header, int fd)
{
	t_save	*target;

	target = header->next;
	while (target)
	{
		if (target->fd == fd)
			return (target);
		target = target->next;
	}
	target = (t_save *)malloc(sizeof(t_save));
	if (!target)
		return (0);
	target->fd = fd;
	target->save = 0;
	target->prev = header;
	target->next = header->next;
	if (header->next)
		header->next->prev = target;
	header->next = target;
	return (target);
}

static char	*ft_string_adder(int fd, char *save)
{
	ssize_t	rbyte;
	char	*buf;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
	{
		if (save)
			free(save);
		return (0);
	}
	rbyte = fd + 1;
	while (rbyte > 0 && !ft_my_strchr(save, '\n'))
	{
		rbyte = read(fd, buf, BUFFER_SIZE);
		if (rbyte == -1)
			break ;
		buf[rbyte] = '\0';
		save = ft_my_strjoin(save, buf);
		if (!save)
			break ;
	}
	free(buf);
	if (rbyte == -1)
		return (0);
	return (save);
}

static char	*ft_get_line(char *save)
{
	char	*line;
	char	*nl_ptr;

	if (*save == '\0')
		return (0);
	nl_ptr = ft_my_strchr(save, '\n');
	if (!nl_ptr)
		return (ft_strdup(save));
	line = (char *)malloc(sizeof(char) * (nl_ptr - save + 2));
	if (!line)
		return (0);
	ft_my_strlcpy(line, save, nl_ptr - save + 2);
	return (line);
}

static char	*ft_save_remain(char *save, char **print_line)
{
	char	*line;
	char	*nl_ptr;

	nl_ptr = ft_my_strchr(save, '\n');
	if (!nl_ptr)
	{
		free(save);
		return (0);
	}
	line = ft_strdup(nl_ptr + 1);
	if (!line)
	{
		free(*print_line);
		*print_line = 0;
	}
	free(save);
	return (line);
}
