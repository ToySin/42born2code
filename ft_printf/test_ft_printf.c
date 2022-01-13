#include "ft_printf.h"
#include <limits.h>

int	main(void)
{
	int		n;
	char	*empty = "";
	char	*null = NULL;

	//basic c
	n = ft_printf("\n\nbasic c: %c %c\n", '4', '2');
	ft_putstr_fd("print byte: ", 1);
	ft_putnbr_fd(n, 1);
	//overflow c
	n = ft_printf("\n\noverflow c: %c\n", 128);
	ft_putstr_fd("print byte: ", 1);
	ft_putnbr_fd(n, 1);

	//empty s
	n = ft_printf("\n\n\nempty s: %s\n", empty);
	ft_putstr_fd("print byte: ", 1);
	ft_putnbr_fd(n, 1);
	//basic s
	n = ft_printf("\n\nbasic s: %s\n", "Hello 42");
	ft_putstr_fd("print byte: ", 1);
	ft_putnbr_fd(n, 1);
	//null s
	n = ft_printf("\n\nnull s: %s\n", null);
	ft_putstr_fd("print byte: ", 1);
	ft_putnbr_fd(n, 1);

	//basic p
	n = ft_printf("\n\n\nbasic p: %p\n", empty);
	ft_putstr_fd("print byte: ", 1);
	ft_putnbr_fd(n, 1);
	//null p
	n = ft_printf("\n\nnull p: %p\n", null);
	ft_putstr_fd("print byte: ", 1);
	ft_putnbr_fd(n, 1);

	//basic d i
	n = ft_printf("\n\n\nbasic d i: %d %i\n", 42, 24);
	ft_putstr_fd("print byte: ", 1);
	ft_putnbr_fd(n, 1);
	//overflow d i
	n = ft_printf("\n\noverflow d i: %d %i\n", INT_MAX + 1, INT_MIN - 1);
	ft_putstr_fd("print byte: ", 1);
	ft_putnbr_fd(n, 1);

	//basic u
	n = ft_printf("\n\n\nbasic u: %u\n", INT_MAX * 2);
	ft_putstr_fd("print byte: ", 1);
	ft_putnbr_fd(n, 1);
	//overflow u
	n = ft_printf("\n\noverflow u: %u %u\n", LONG_MAX + 1, -1);
	ft_putstr_fd("print byte: ", 1);
	ft_putnbr_fd(n, 1);
	
	//basic x X
	n = ft_printf("\n\n\nbasic x X: %x %X\n", 42, 4242);
	ft_putstr_fd("print byte: ", 1);
	ft_putnbr_fd(n, 1);
	//overflow x X
	n = ft_printf("\n\noverflow x X: %x %X\n", LONG_MAX + 1, -1);
	ft_putstr_fd("print byte: ", 1);
	ft_putnbr_fd(n, 1);

	//single %
	n = ft_printf("\n\n\nsingle %%: %%\n");
	ft_putstr_fd("print byte: ", 1);
	ft_putnbr_fd(n, 1);
	//multiple %
	n = ft_printf("\n\nmultiple %%: %% %%%% %%%%%% %%%% %%");
	ft_putstr_fd("print byte: ", 1);
	ft_putnbr_fd(n, 1);

	//mix
}
