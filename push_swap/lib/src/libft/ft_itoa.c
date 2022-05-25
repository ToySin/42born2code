/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donshin <donshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 00:25:43 by donshin           #+#    #+#             */
/*   Updated: 2021/12/02 14:13:03 by donshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static int	number_of_digits(unsigned int n);

char	*ft_itoa(int n)
{
	unsigned int	num;
	char			*rst;
	int				len;

	num = n;
	if (n < 0)
		num = -n;
	else if (!n)
		return (ft_strdup("0"));
	len = number_of_digits(num);
	if (n < 0)
		len++;
	rst = (char *)malloc(sizeof(char) * (len + 1));
	if (!rst)
		return (0);
	if (n < 0)
		rst[0] = '-';
	rst[len] = '\0';
	while (num > 0)
	{
		rst[--len] = num % 10 + '0';
		num /= 10;
	}
	return (rst);
}

static int	number_of_digits(unsigned int n)
{
	int	count;

	count = 0;
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}
