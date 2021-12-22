#include <stdio.h>
#include <stdlib.h>

void free_func(char *str)
{
	free(str);
	char *tmp = (char *)malloc(sizeof(char));
	str = tmp;
}

void func()
{
	static char *str;
	char *tmp = (char *)malloc(sizeof(char));
	printf("%p\n", str);

	str = (char *)malloc(sizeof(char));
	printf("%p\n", str);

	free_func(str);
	printf("%p\n", str);

	str = tmp;
	printf("%p\n", str);
}

int main()
{
	func();
	return (0);
}
