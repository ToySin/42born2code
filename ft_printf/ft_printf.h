/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 15:04:52 by donshin           #+#    #+#             */
/*   Updated: 2021/12/31 23:29:55 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_type_info
{
	char	*type;
}			t_type_info;

int	ft_printf(const char *format, ...);

int	manage_conv(const char *format, va_list ap);
int	decode_type(t_type_info *info, const char *format);
int	print_args(t_type_info *info, va_list ap);

int

#endif
