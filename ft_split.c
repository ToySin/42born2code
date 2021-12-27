/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 00:51:47 by donshin           #+#    #+#             */
/*   Updated: 2021/11/25 18:04:06 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_sep(char const *s, char c);
static int	ft_cnt_word(char const *s, char c);
static char	*ft_to_find(char const *s, char c);
static char	**ft_free_strs(char **strs);

char	**ft_split(char const *s, char c)
{
	char	**strs;
	char	*start;
	int		word_i;

	strs = (char **)malloc(sizeof(char *) * (ft_cnt_word(s, c) + 1));
	if (!strs)
		return (NULL);
	word_i = 0;
	while (1)
	{
		if (!ft_is_sep(s, c))
		{
			start = (char *)s;
			s = ft_to_find(s, c);
			strs[word_i] = (char *)malloc(sizeof(char) * (s - start + 1));
			if (!strs[word_i])
				return (ft_free_strs(strs));
			ft_strlcpy(strs[word_i++], start, s - start + 1);
		}
		if (!(*s++))
			break ;
	}
	strs[word_i] = NULL;
	return (strs);
}

static int	ft_is_sep(char const *s, char c)
{
	return (*s == c || !(*s));
}

static int	ft_cnt_word(char const *s, char c)
{
	int		word_cnt;

	if (!s)
		return (-2);
	word_cnt = 0;
	while (1)
	{
		if (!ft_is_sep(s, c))
		{
			word_cnt++;
			s = ft_to_find(s, c);
		}
		if (!(*s++))
			break ;
	}
	return (word_cnt);
}

static char	*ft_to_find(char const *s, char c)
{
	while (*s && *s != c)
		s++;
	return ((char *)s);
}

static char	**ft_free_strs(char **strs)
{
	size_t	word_idx;

	word_idx = 0;
	while (strs[word_idx])
		free(strs[word_idx++]);
	free(strs);
	return (NULL);
}
