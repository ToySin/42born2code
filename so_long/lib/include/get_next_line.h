/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 13:27:35 by donshin           #+#    #+#             */
/*   Updated: 2022/03/12 16:02:59 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

typedef struct s_save
{
	int				fd;
	char			*save;
	struct s_save	*prev;
	struct s_save	*next;
}					t_save;

char	*get_next_line(int fd);

void	ft_my_strlcpy(char *dest, const char *src, size_t dstsize);
char	*ft_my_strchr(char *s, int c);
char	*ft_my_strjoin(char *s1, char *s2);
void	ft_my_lstdelone(t_save *lst);

#endif
