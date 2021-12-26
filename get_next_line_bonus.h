/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 13:27:35 by donshin           #+#    #+#             */
/*   Updated: 2021/12/26 22:29:38 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100000
# endif

typedef struct s_save
{
	int				fd;
	char			*save;
	struct s_save	*prev;
	struct s_save	*next;
}					t_save;

char	*get_next_line(int fd);

char	*ft_my_strchr(char *s, int c);
char	*ft_my_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s);
t_save	*ft_my_lstnew(int fd);
void	ft_my_lstdelone(t_save *lst);

#endif
