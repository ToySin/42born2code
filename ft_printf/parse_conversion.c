/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 15:32:01 by donshin           #+#    #+#             */
/*   Updated: 2022/01/02 23:59:05 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_conversion(const char **format, va_list ap, int *byte)
{
	t_info		info;

	decode_conversion(format, &info);
	print_arg(&info, ap, byte);
}
