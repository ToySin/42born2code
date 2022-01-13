/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 18:52:56 by donshin           #+#    #+#             */
/*   Updated: 2022/01/13 15:05:10 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_valid_format(const char *format)
{
	if (!format)
		return (0);
	while (*format)
	{
		if (ft_strchr("%", *format))
			if (!ft_strchr("cspdiuxX%", *(++format)))
				return (0);
		format++;
	}
	return (1);
}
