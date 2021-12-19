/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 21:16:24 by donshin           #+#    #+#             */
/*   Updated: 2021/11/19 11:52:10 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			index;

	if (!n)
		return (0);
	index = 0;
	while (index + 1 < n)
	{
		if (*(const unsigned char *)s1 != *(const unsigned char *)s2)
			break ;
		s1++;
		s2++;
		index++;
	}
	return (*(const unsigned char *)s1 - *(const unsigned char *)s2);
}
