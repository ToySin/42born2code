/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 15:04:52 by donshin           #+#    #+#             */
/*   Updated: 2022/01/02 14:38:43 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

int		ft_printf(const char *format, ...);
int		is_valid_format(const char *format);
void	parse_conversion(const char **format, va_list ap, int *byte);

void	print_args(va_list ap, char type, int *byte;);

void	print_char(int c, int *byte);
void	print_string(char *s, int *byte);
void	print_int(int nbr, int *byte);
void	print_unsigned_int(unsigned int nbr, int *byte);
void	print_pointer(void *ptr, int *byte);

int	print_c(char *c);
int	print_s(char *s);
int	print_p(unsigned long *ptr);
int	print_d(int integer);
int	print_i(int integer);
int	print_u(unsigned int u_integer);
int	print_x(va_list ap);
int	print_X(va_list ap);



#endif
