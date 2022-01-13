/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 15:04:52 by donshin           #+#    #+#             */
/*   Updated: 2022/01/13 11:03:53 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

int		ft_printf(const char *format, ...);
int		is_valid_format(const char *format);

void	parse_conversion(const char **format, va_list ap, int *byte);
void	print_arg(char type, va_list ap, int *byte);

void	print_char(char c, int *byte);
void	print_string(char *s, int *byte);
void	print_nbr(char type, unsigned long nbr, int *byte);

#endif
