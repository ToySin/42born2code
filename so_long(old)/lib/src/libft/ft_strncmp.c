/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 21:14:00 by donshin           #+#    #+#             */
/*   Updated: 2021/11/19 11:53:54 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;

	if (!n)
		return (0);
	index = 0;
	while (index + 1 < n && *s1 && *s2)
	{
		if (*(const unsigned char *)s1 != *(const unsigned char *)s2)
			break ;
		s1++;
		s2++;
		index++;
	}
	return (*(const unsigned char *)s1 - *(const unsigned char *)s2);
}
