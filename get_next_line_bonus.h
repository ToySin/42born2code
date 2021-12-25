/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 13:27:35 by donshin           #+#    #+#             */
/*   Updated: 2021/12/25 18:37:16 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

#include <stdio.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
# endif

# ifndef OPEN_MAX
# define OPEN_MAX 128
# endif

char	*get_next_line(int fd);

size_t	ft_strlen(char *s);
size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize);
char	*ft_my_strchr(char *s, int c);
char	*ft_my_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s);

#endif
