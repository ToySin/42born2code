/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 11:41:48 by donshin           #+#    #+#             */
/*   Updated: 2021/12/19 17:01:31 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

#include <stdio.h>

# define BUFFER_SIZE 42

char	*get_next_line(int fd);

size_t	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);

#endif
