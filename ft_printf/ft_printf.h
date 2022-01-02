/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 15:04:52 by donshin           #+#    #+#             */
/*   Updated: 2022/01/02 23:22:50 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_info
{
	char	*converted_str;
	char	type;
	int		arg_len;
}			t_info;


int		ft_printf(const char *format, ...);
int		is_valid_format(const char *format);

void	parse_conversion(const char **format, va_list ap, int byte);
void	decode_conversion(cons char **format, t_info *info);
void	convert_arg(t_info *info, va_list ap);





#endif
