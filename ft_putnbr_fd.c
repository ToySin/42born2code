/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 10:36:31 by donshin           #+#    #+#             */
/*   Updated: 2021/12/01 20:22:08 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_recursive_fd(unsigned int num, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	num;

	if (n < 0)
	{
		write(fd, "-", 1);
		num = -n;
	}
	else
		num = n;
	ft_putnbr_recursive_fd(num, fd);
}

static void	ft_putnbr_recursive_fd(unsigned int num, int fd)
{
	if (num / 10)
		ft_putnbr_recursive_fd(num / 10, fd);
	write(fd, &"0123456789"[num % 10], 1);
}
