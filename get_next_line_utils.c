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

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	s_len;
	size_t	index;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len < start)
		return (ft_strjoin("", ""));
	if (s_len - start < len)
		len = s_len - start;
	sub_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub_str)
		return (NULL);
	index = 0;
	while (index < len)
	{
		sub_str[index] = s[start + index];
		index++;
	}
	sub_str[index] = '\0';
	return (sub_str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*joined;
	size_t	s1_len;
	size_t	s2_len;
	size_t	total_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	joined = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!joined)
		return (NULL);
	total_len = 0;
	while (total_len < s1_len)
	{
		joined[total_len] = s1[total_len];
		total_len++;
	}
	total_len = 0;
	while (total_len < s2_len)
	{
		joined[s1_len + total_len] = s2[total_len];
		total_len++;
	}
	joined[s1_len + s2_len] = '\0';
	return (joined);
}

char	*ft_strchr(char *s, int c)
{
	if (!c)
		return (s + ft_strlen(s));
	while (*s)
	{
		if (*s == (char)c)
			return (s);
		s++;
	}
	return (NULL);
}
