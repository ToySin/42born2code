/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:03:05 by donshin           #+#    #+#             */
/*   Updated: 2022/01/13 15:17:38 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	rprint_nbr_base(unsigned long nbr, char *base, int rdx, int *byte);

void	print_nbr(char type, unsigned long nbr, int *byte)
{
	if (ft_strchr("di", type))
	{
		if ((int)nbr < 0)
		{
			*byte += (int)write(1, "-", 1);
			nbr = (unsigned int) -(int)nbr;
		}
		rprint_nbr_base((unsigned int)(int)nbr, "0123456789", 10, byte);
	}
	else if (ft_strchr("u", type))
		rprint_nbr_base((unsigned int)nbr, "0123456789", 10, byte);
	else if (ft_strchr("x", type))
		rprint_nbr_base((unsigned int)nbr, "0123456789abcdef", 16, byte);
	else if (ft_strchr("X", type))
		rprint_nbr_base((unsigned int)nbr, "0123456789ABCDEF", 16, byte);
	else if (ft_strchr("p", type))
	{
		*byte += (int)write(1, "0x", 2);
		rprint_nbr_base(nbr, "0123456789abcdef", 16, byte);
	}
}

static void	rprint_nbr_base(unsigned long nbr, char *base, int rdx, int *byte)
{
	if (nbr / rdx)
		rprint_nbr_base(nbr / rdx, base, rdx, byte);
	*byte += (int)write(1, &base[nbr % rdx], 1);
}
