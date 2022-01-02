/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 23:55:28 by donshin           #+#    #+#             */
/*   Updated: 2022/01/03 00:05:47 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_arg(t_info *info, va_list ap, int *byte)
{
	char type;

	type = info->type;
	if (ft_strcmp("c", type))
		print_char(info, (char)va_arg(ap, int), byte);
	else if (ft_strcmp("s", type))
		print_string(info, va_arg(ap, char *), byte);
	else if (ft_strcmp("p", type))
		print_nbr(info, va_arg(ap, unsigned long), byte);
	else if (ft_strchr("di", type))
		print_nbr(info, va_arg(ap, int), byte);
	else if (ft_strcmp("uxX", type))
		print_nbr(info, va_arg(ap, unsigned int), byte);
	else if (ft_strcmp("%", type))
		print_char(info, '%', byte);
}
