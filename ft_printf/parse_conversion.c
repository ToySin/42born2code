/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 15:32:01 by donshin           #+#    #+#             */
/*   Updated: 2022/01/03 16:51:14 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_conversion(const char **format, va_list ap, int *byte)
{
	const char	*format_ptr;

	format_ptr = *(++format);
	write(1, format_ptr, 1); //이것도 안나오네..
	print_arg(*format_ptr++, ap, byte);
	*format = format_ptr;
}
