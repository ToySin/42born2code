/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 15:04:52 by donshin           #+#    #+#             */
/*   Updated: 2021/12/30 16:27:45 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_conv
{

}

int	ft_printf(const char *format, ...);

int	ft_manage_conversion(const char *format, va_list ap);
int	ft_determinating_conversion_type(int c);

#endif
