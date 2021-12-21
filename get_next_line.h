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

# define BUFFER_SIZE 42

char	*get_next_line(int fd);

ssize_t	*ft_search_and_set_nl(char *str);
char	*ft_string_adder(char *save, char *buf);
char	*ft_linetrim(char *save, char *buf, ssize_t offset);

size_t	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);

#endif
