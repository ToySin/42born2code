/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 21:17:45 by donshin           #+#    #+#             */
/*   Updated: 2021/12/02 14:05:41 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (!c)
		return ((char *)s + ft_strlen((char *)s));
	while (*s)
	{
		if (*(char *)s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}
