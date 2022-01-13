/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:03:21 by donshin           #+#    #+#             */
/*   Updated: 2022/01/13 11:04:52 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_string(char *s, int *byte)
{
	if (!s)
		*byte += (int)write(1, "(null)", 6);
	else
		*byte += (int)write(1, s, ft_strlen(s));
}
