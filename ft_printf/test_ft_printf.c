#include "ft_printf.h"
#include <limits.h>

int main(void)
{
	int		n;
	char	*empty = "";
	char	*null = NULL;

	//basic c
	ft_printf("basic c: ");
	n = ft_printf("%c%c", '4', '2');
	ft_printf("\nprint byte: %d\n", n);
	//overflow c
	ft_printf("overflow c: ");
	n = ft_printf("%c", 128);
	ft_printf("\nprint byte: %d\n", n);
	

	//empty s
	ft_printf("\nempty s: ");
	n = ft_printf("%s", empty);
	ft_printf("\nprint byte: %d\n", n);
	//basic s
	ft_printf("basic s: ");
	n = ft_printf("%s", "Hello 42");
	ft_printf("\nprint byte: %d\n", n);
	//null s
	ft_printf("null s: ");
	n = ft_printf("%s", null);
	ft_printf("\nprint byte: %d\n", n);
	

	//basic p
	ft_printf("\nbasic p: ");
	n = ft_printf("%p", empty);
	ft_printf("\nprint byte: %d\n", n);
	//null p
	ft_printf("null p: ");
	n = ft_printf("%p", null);
	ft_printf("\nprint byte: %d\n", n);
	

	//basic d i
	ft_printf("\nbasic d i: ");
	n = ft_printf("%d %i", 42, 24);
	ft_printf("\nprint byte: %d\n", n);
	//overflow d i
	ft_printf("overflow d i: ");
	n = ft_printf("%d %i", INT_MAX + 1, INT_MIN - 1);
	ft_printf("\nprint byte: %d\n", n);
	

	//basic u
	ft_printf("\nbasic u: ");
	n = ft_printf("%u", INT_MAX * 2);
	ft_printf("\nprint byte: %d\n", n);
	//overflow u
	ft_printf("overflow u: ");
	n = ft_printf("%u %u", UINT_MAX + 1, -1);
	ft_printf("\nprint byte: %d\n", n);


	//basic x X
	ft_printf("\nbasic x X: ");
	n = ft_printf("%x %X", 42, 4242);
	ft_printf("\nprint byte: %d\n", n);
	//overflow x X
	ft_printf("overflow x X: ");
	n = ft_printf("%x %X", UINT_MAX + 1, -1);
	ft_printf("\nprint byte: %d\n", n);
	

	//single %
	ft_printf("\nsingle %%: ");
	n = ft_printf("%%");
	ft_printf("\nprint byte: %d\n", n);
	//multiple %
	ft_printf("multiple %%: ");
	n = ft_printf("%% %%%% %%%%%% %%%% %%");
	ft_printf("\nprint byte: %d\n", n);
	

	//mix
	ft_printf("\nmix : ");
	n = ft_printf("%s%c%c%c%c%c. %d %% %i = %u", "Hello", 'w', 'o', 'r', 'l', 'd', 6, 3, 0);
	ft_printf("\nprint byte: %d\n", n);
}