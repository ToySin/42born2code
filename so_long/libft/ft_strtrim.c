/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 23:42:25 by donshin           #+#    #+#             */
/*   Updated: 2021/11/25 16:58:52 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	char	*end;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = (char *)s1;
	while (*start && ft_strchr(set, *start))
		start++;
	end = (char *)s1 + ft_strlen(s1);
	while (start <= end && ft_strchr(set, *(end - 1)))
		end--;
	return (ft_substr(s1, start - s1, end - start));
}
