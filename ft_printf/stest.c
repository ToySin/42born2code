#include "ft_printf.h"

void 	prr(char type, ...)
{
	va_list ap;
	int byte = 0;

	va_start(ap, type);
	print_string(va_arg(ap, char *), &byte);
	byte += (int)write(1, "Nooo", 4);
	print_nbr('d', byte, &byte);
}

int main() {
	// int a = 0;
	// print_char('a', &a);
	// prr('s', "Hello world!");

	// printf("%d", (int)write(1, "main", 4));
	int n;

	n = ft_printf(" %% \n");
	n += ft_printf(" %% %% \n");
	n += ft_printf(" %% %%%%\n");
	n += ft_printf("%d\n", 5000);
	n += ft_printf("%s", "Hello boy\n");
	n += ft_printf("%c\n", 'a');
	n += ft_printf("%p\n", &n);
	ft_printf("%d", n);
	printf("%p\n", &n);
}
