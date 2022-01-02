/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 23:37:02 by donshin           #+#    #+#             */
/*   Updated: 2022/01/02 13:05:34 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_args(va_list ap, char type, int *byte)
{
	if (ft_strcmp("c", type))
	{
		print_char(va_arg(ap, int), byte);
	}
	else if (ft_strcmp("s", type))
	{
		print_string(va_arg(ap, char *), byte);
	}
	else if (ft_strcmp("p", type))
	{
		va_arg(ap, unsigned long);
	}
	else if (ft_strchr("uxX", type))
	{
		va_arg(ap, unsigned int);
	}
	else if (ft_strchr("di", type))
	{
		va_arg(ap, int);
	}
	else if (ft_strcmp("%", type))
	{
		print_char("%", type);
	}
}
