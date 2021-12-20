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
# include <stdlib.h>

# define BUFFER_SIZE 42

char	*get_next_line(int fd);

ssize_t	*ft_search_nl(char *str);


size_t	ft_strlen(char *str);
size_t	ft_strlcpy(char *dest, char *src, size_t nbyte);
size_t	ft_strlcat(char *dest, char *src, size_t nbyte);
char	*ft_strjoin(char *s1, char *s2);

#endif
