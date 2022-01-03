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
	ft_printf("a%%");
}
