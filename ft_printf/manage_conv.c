/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 15:32:01 by donshin           #+#    #+#             */
/*   Updated: 2021/12/31 23:42:03 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	manage_conv(const char *format, va_list ap)
{
	t_type_info info;

	decode_type(&info, format + 1);
	print_args(&info, ap);
}
