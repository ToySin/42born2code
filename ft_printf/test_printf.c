#include <stdio.h>
#include <limits.h>

int main(void)
{
	int		n;
	char	*empty = "";
	char	*null = NULL;

	//basic c
	printf("basic c: ");
	n = printf("%c%c", '4', '2');
	printf("\nprint byte: %d\n", n);
	//overflow c
	printf("overflow c: ");
	n = printf("%c", 128);
	printf("\nprint byte: %d\n", n);
	

	//empty s
	printf("\nempty s: ");
	n = printf("%s", empty);
	printf("\nprint byte: %d\n", n);
	//basic s
	printf("basic s: ");
	n = printf("%s", "Hello 42");
	printf("\nprint byte: %d\n", n);
	//null s
	printf("null s: ");
	n = printf("%s", null);
	printf("\nprint byte: %d\n", n);
	

	//basic p
	printf("\nbasic p: ");
	n = printf("%p", empty);
	printf("\nprint byte: %d\n", n);
	//null p
	printf("null p: ");
	n = printf("%p", null);
	printf("\nprint byte: %d\n", n);
	

	//basic d i
	printf("\nbasic d i: ");
	n = printf("%d %i", 42, 24);
	printf("\nprint byte: %d\n", n);
	//overflow d i
	printf("overflow d i: ");
	n = printf("%d %i", INT_MAX + 1, INT_MIN - 1);
	printf("\nprint byte: %d\n", n);
	

	//basic u
	printf("\nbasic u: ");
	n = printf("%u", INT_MAX * 2);
	printf("\nprint byte: %d\n", n);
	//overflow u
	printf("overflow u: ");
	n = printf("%u %u", UINT_MAX + 1, -1);
	printf("\nprint byte: %d\n", n);


	//basic x X
	printf("\nbasic x X: ");
	n = printf("%x %X", 42, 4242);
	printf("\nprint byte: %d\n", n);
	//overflow x X
	printf("overflow x X: ");
	n = printf("%x %X", UINT_MAX + 1, -1);
	printf("\nprint byte: %d\n", n);
	

	//single %
	printf("\nsingle %%: ");
	n = printf("%%");
	printf("\nprint byte: %d\n", n);
	//multiple %
	printf("multiple %%: ");
	n = printf("%% %%%% %%%%%% %%%% %%");
	printf("\nprint byte: %d\n", n);
	

	//mix
	printf("\nmix : ");
	n = printf("%s%c%c%c%c%c. %d %% %i = %u", "Hello", 'w', 'o', 'r', 'l', 'd', 6, 3, 0);
	printf("\nprint byte: %d\n", n);
}