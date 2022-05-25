/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 21:15:21 by donshin           #+#    #+#             */
/*   Updated: 2021/11/23 19:26:21 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			index;
	unsigned char	*rst;

	if (!dest && !src)
		return (0);
	rst = (unsigned char *)dest;
	index = 0;
	while (index < n)
	{
		*(unsigned char *)dest = *(const unsigned char *)src;
		index++;
		dest++;
		src++;
	}
	return ((void *)rst);
}
