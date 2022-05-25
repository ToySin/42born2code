/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 21:18:03 by donshin           #+#    #+#             */
/*   Updated: 2021/12/02 14:08:35 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*prev;

	if (!c)
		return (ft_strchr(s, c));
	prev = 0;
	while (1)
	{
		s = (const char *)ft_strchr(s, c);
		if (!s)
			return (prev);
		prev = (char *)s;
		s++;
	}
}
