/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 14:59:43 by donshin           #+#    #+#             */
/*   Updated: 2021/12/30 16:08:01 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	print_byte;
	size_t	conversion_byte;

	va_start(ap, format);
	print_byte = 0;
	while (*format)
	{
		if (*format == '%')
			conversion_byte = ft_manage_conversion(format, ap);
		else
		{
			ft_putchar_fd(*format, 1);
			conversion_byte = 1;
		}
		print_byte += conversion_byte;
		format += conversion_byte;
	}
	va_end(ap);
	return (print_byte);
}
