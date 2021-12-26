/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 13:40:28 by donshin           #+#    #+#             */
/*   Updated: 2021/12/27 01:24:55 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_my_strlcpy(char *dest, const char *src, size_t dstsize)
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
}

char	*ft_my_strchr(char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return (s);
		s++;
	}
	return (NULL);
}

char	*ft_my_strjoin(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*comb;

	if (!s1)
		return (ft_strdup(s2));
	s1_len = 0;
	while (s1[s1_len])
		s1_len++;
	s2_len = 0;
	while (s2[s2_len])
		s2_len++;
	comb = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!comb)
		return (NULL);
	ft_my_strlcpy(comb, s1, s1_len + 1);
	ft_my_strlcpy(comb + s1_len, s2, s2_len + 1);
	free(s1);
	return (comb);
}

char	*ft_strdup(char *s)
{
	size_t	len;
	char	*dup;

	if (!s)
		return (NULL);
	len = 0;
	while (s[len])
		len++;
	dup = (char *)malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	ft_my_strlcpy(dup, s, len + 1);
	return (dup);
}

void	ft_my_lstdelone(t_save *lst)
{
	lst->prev->next = lst->next;
	lst->next->prev = lst->prev;
	free(lst);
}
