/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 11:41:45 by donshin           #+#    #+#             */
/*   Updated: 2021/12/22 15:35:01 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static ssize_t	ft_search_and_set_nl(char *str);
static char		*ft_string_adder(char *save, char *buf);
static char		*ft_linetrim(char *save, char *buf, ssize_t offset);

char	*get_next_line(int fd)
{
	static char	*save;
	char		*buf;
	ssize_t		offset;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	offset = -1;

	if (save)
	{
		printf("\n == start_get_next_line ==\n");
		for (int i = 0; i < BUFFER_SIZE; i++)
			printf(" %d", save[i]);
		printf("\n");
	}

	while (offset == -1)
	{
		offset = read(fd, buf, BUFFER_SIZE);

		printf("read offset: %ld\n", offset);

		if (offset < 1)
		{
			if (!offset)
				offset = -1;
			break ;
		}
		buf[offset] = '\0';
		save = ft_string_adder(save, buf);
		offset = ft_search_and_set_nl(save);

		printf("nl offset: %ld\n", offset);
	}

	printf("\n == end_get_next_line ==\n");
	for (int i = 0; i < BUFFER_SIZE; i++)
		printf(" %d", save[i]);
	printf("\n");

	return (ft_linetrim(save, buf, offset));
}

static ssize_t	ft_search_and_set_nl(char *str)
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

static char	*ft_string_adder(char *save, char *buf)
{
	char	*result;

	if (save)
		result = ft_strjoin(save, buf);
	else
		result = ft_strjoin("\0", buf);
	free(save);
	return (result);
}

static char	*ft_linetrim(char *save, char *buf, ssize_t offset)
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

	if (save)
	{
		printf("\n == ft_linetrim ==\n");
		for (int i = 0; i < BUFFER_SIZE; i++)
			printf(" %d", save[i]);
		printf("\n");
	}

	return (trimed);
}
