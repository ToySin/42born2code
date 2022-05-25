/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 21:17:28 by donshin           #+#    #+#             */
/*   Updated: 2022/03/01 18:11:47 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	index;
	size_t	dst_len;

	dst_len = ft_strlen(dst);
	if (dst_len >= size)
		return (size + ft_strlen(src));
	index = 0;
	while (index < size - dst_len - 1 && src[index])
	{
		dst[dst_len + index] = src[index];
		index++;
	}
	dst[dst_len + index] = '\0';
	return (dst_len + ft_strlen(src));
}
