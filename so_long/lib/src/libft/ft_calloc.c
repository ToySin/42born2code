/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 21:11:30 by donshin           #+#    #+#             */
/*   Updated: 2022/03/01 18:11:47 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*result;

	result = (char *)malloc(nmemb * size);
	if (!result)
		return (0);
	ft_memset(result, 0, nmemb * size);
	if (!nmemb || !size)
		result[0] = 0;
	return (result);
}
