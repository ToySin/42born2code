/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 21:29:47 by donshin           #+#    #+#             */
/*   Updated: 2021/12/19 21:29:47 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

size_t	ft_strlcpy(char *dest, char *src, size_t nbyte)
{
	size_t	index;

	index = 0;
	while (index + 1 < nbyte && src[index])
	{
		dest[index] = src[index];
		index++;
	}
	if (nbyte)
		dest[index] = '\0';
	return (ft_strlen(src));
}

size_t	ft_strlcat(char *dest, char *src, size_t nbyte)
{
	size_t	index;
	size_t	dst_len;

	dst_len = ft_strlen(dest);
	if (dst_len >= nbyte)
		return (nbyte + ft_strlen(src));
	index = 0;
	while (index + 1 < nbyte - dst_len && src[index])
	{
		dest[dst_len + index] = src[index];
		index++;
	}
	dest[dst_len + index] = '\0';
	return (dst_len + ft_strlen(src));
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*joined;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	joined = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!joined)
		return (NULL);
	joined[0] = '\0';
	ft_strlcat(joined, s1, s1_len + 1);
	ft_strlcat(joined, s2, s1_len + s2_len + 1);
	return (joined);
}
