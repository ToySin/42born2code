/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 21:13:06 by donshin           #+#    #+#             */
/*   Updated: 2021/12/02 14:03:33 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	long	result;
	int		sign;

	while ((9 <= *nptr && *nptr <= 13) || *nptr == 32)
		nptr++;
	sign = 1;
	if (*nptr == '+' || *nptr == '-')
		if (*nptr++ == '-')
			sign = -1;
	result = 0;
	while (ft_isdigit(*nptr))
		result = result * 10 + (*nptr++ - '0');
	if (result < 0)
		return ((sign + 1) / -2);
	return (sign * result);
}
