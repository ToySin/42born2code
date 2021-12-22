#include <stdio.h>
#include <stdlib.h>

void func()
{
	static char *str;
	printf("%p\n", str);

	str = (char *)malloc(sizeof(char));
	printf("%p\n", str);

	free(str);
	printf("%p\n", str);
}

int main()
{
	func();
	return (0);
}
