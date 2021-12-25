/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 13:27:35 by donshin           #+#    #+#             */
/*   Updated: 2021/12/25 21:24:04 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
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
