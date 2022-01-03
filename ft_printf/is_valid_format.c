/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 18:52:56 by donshin           #+#    #+#             */
/*   Updated: 2022/01/03 14:57:12 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_valid_format(const char *format)
{
	while (*format)
	{
		if (ft_strchr("%", *format))
			if (!ft_strchr("cspdiuxX%", *format))
				return (0);
		format++;
	}
	return (1);
}

// #include <stdio.h>

// int main() {
// 	printf("%d", is_valid_format("%c%s%p%d%%%u%i%x%X"));
// 	printf("%d", is_valid_format("%c%s%p%d%%%u%i%y%X"));
// }

// gcc is_valid_format.c libft/ft_strchr.c libft/ft_strlen.c

// check done
