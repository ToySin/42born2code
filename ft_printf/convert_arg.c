/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 23:28:12 by donshin           #+#    #+#             */
/*   Updated: 2022/01/02 23:44:29 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convert_arg(t_info *info, va_list ap)
{
	char type;

	type = info->type;

	if (ft_strcmp("c", type))
		convert_char(info, va_arg(ap, int));
	else if (ft_strcmp("s", type))
		convert_stype(info, va_arg(ap, char *));
	else if (ft_strcmp("p", type))
	{
		convert_
	}
	else if (ft_strchr("di", type))
	{

	}
	else if (ft_strcmp("u", type))
	{

	}
	else if (ft_strchr("xX", type))
	{

	}
	else if (ft_strcmp("%", type))
	{
		info->converted_str = ft_strdup("%");
		info->arg_len = 1;
	}
}
