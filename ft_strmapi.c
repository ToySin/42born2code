/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 01:04:06 by donshin           #+#    #+#             */
/*   Updated: 2021/11/23 21:00:14 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	index;
	char	*rst;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	index = 0;
	rst = (char *)malloc(sizeof(char) * (len + 1));
	if (!rst)
		return (NULL);
	while (index < len)
	{
		rst[index] = f(index, s[index]);
		index++;
	}
	rst[index] = '\0';
	return (rst);
}
