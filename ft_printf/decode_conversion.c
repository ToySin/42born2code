/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decode_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 23:15:24 by donshin           #+#    #+#             */
/*   Updated: 2022/01/02 23:24:31 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// decode conversion flag and type
// move format pointer in ft_printf function next to conversion

void	decode_conversion(const char **format, t_info *info)
{
	char	*format_ptr;

	format_ptr = *(++format);
	info->type = *(format_ptr++);
	*format = format_ptr;
}
