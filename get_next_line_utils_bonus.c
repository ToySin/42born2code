/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 13:40:28 by donshin           #+#    #+#             */
/*   Updated: 2021/12/24 16:30:01 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	index;

	index = 0;
	while (index + 1 < dstsize && src[index])
	{
		dest[index] = src[index];
		index++;
	}
	if (dstsize)
		dest[index] = '\0';
	return (ft_strlen(src));
}

char	*ft_strchr(char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return (s);
		s++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	len;
	char	*comb;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	comb = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!comb)
		return (NULL);
	ft_strlcpy(comb, s1, s1_len + 1);
	ft_strlcpy(comb + s1_len, s2, s2_len + 1);
	return (comb);
}

char	*ft_strdup(char *s)
{
	size_t	len;
	size_t	index;
	char	*dup;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	dup = (char *)malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	index = 0;
	while (index < len)
	{
		dup[index] = s[index];
		index++;
	}
	dup[index] = '\0';
	return (dup);
}
