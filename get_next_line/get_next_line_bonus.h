/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 13:27:35 by donshin           #+#    #+#             */
/*   Updated: 2021/12/26 23:39:07 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

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
char	*ft_strdup(char *s);
void	ft_my_lstdelone(t_save *lst);

#endif
