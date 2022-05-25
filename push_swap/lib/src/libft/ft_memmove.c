/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 21:15:48 by donshin           #+#    #+#             */
/*   Updated: 2021/11/23 19:30:08 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			index;
	unsigned char	*rst;

	if (!dest && !src)
		return (0);
	rst = (unsigned char *)dest;
	if (dest < src)
		ft_memcpy(dest, src, n);
	else
	{
		index = n;
		while (index > 0)
		{
			*(unsigned char *)(dest + index - 1) = \
			*(const unsigned char *)(src + index - 1);
			index--;
		}
	}
	return (rst);
}
