/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 21:14:27 by donshin           #+#    #+#             */
/*   Updated: 2021/11/23 19:48:34 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;
	size_t	big_index;

	if (!(*little))
		return ((char *)big);
	little_len = ft_strlen(little);
	big_index = 0;
	while (*big && big_index + little_len <= len)
	{
		if (!ft_strncmp(big, little, little_len))
			return ((char *)big);
		big_index++;
		big++;
	}
	return (NULL);
}
