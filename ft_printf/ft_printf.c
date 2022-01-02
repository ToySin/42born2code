/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 14:59:43 by donshin           #+#    #+#             */
/*   Updated: 2022/01/02 23:14:16 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		print_byte;

	if (!is_valid_format(format))
		return (-1);
	va_start(ap, format);
	print_byte = 0;
	while (*format)
	{
		if (*format == '%')
			parse_conversion(&format, ap, &print_byte);
		else
		{
			ft_putchar_fd(*format, 1);
			print_byte++;
			format++;
		}
	}
	va_end(ap);
	return (print_byte);
}
