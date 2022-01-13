#include <stdio.h>
#include <limits.h>

int main(void)
{
	int		n;
	char	*empty = "";
	char	*null = NULL;

	//basic c
	n = printf("\n\nbasic c: %c %c\n", '4', '2');
	printf("print byte: %d", n);
	
	//overflow c
	n = printf("\n\noverflow c: %c\n", 128);
	printf("print byte: %d", n);
	

	//empty s
	n = printf("\n\n\nempty s: %s\n", empty);
	printf("print byte: %d", n);
	
	//basic s
	n = printf("\n\nbasic s: %s\n", "Hello 42");
	printf("print byte: %d", n);
	
	//null s
	n = printf("\n\nnull s: %s\n", null);
	printf("print byte: %d", n);
	

	//basic p
	n = printf("\n\n\nbasic p: %p\n", empty);
	printf("print byte: %d", n);
	
	//null p
	n = printf("\n\nnull p: %p\n", null);
	printf("print byte: %d", n);
	

	//basic d i
	n = printf("\n\n\nbasic d i: %d %i\n", 42, 24);
	printf("print byte: %d", n);
	
	//overflow d i
	n = printf("\n\noverflow d i: %d %i\n", INT_MAX + 1, INT_MIN - 1);
	printf("print byte: %d", n);
	

	//basic u
	n = printf("\n\n\nbasic u: %u\n", INT_MAX * 2);
	printf("print byte: %d", n);
	
	//overflow u
	n = printf("\n\noverflow u: %u %u\n", LONG_MAX + 1, -1);
	printf("print byte: %d", n);
	
	
	//basic x X
	n = printf("\n\n\nbasic x X: %x %X\n", 42, 4242);
	printf("print byte: %d", n);
	
	//overflow x X
	n = printf("\n\noverflow x X: %x %X\n", LONG_MAX + 1, -1);
	printf("print byte: %d", n);
	

	//single %
	n = printf("\n\n\nsingle %%: %%\n");
	printf("print byte: %d", n);
	
	//multiple %
	n = printf("\n\nmultiple %%: %% %%%% %%%%%% %%%% %%");
	printf("print byte: %d", n);
	

	//mix
}