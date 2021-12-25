#include "get_next_line_bonus.h"
#include <stdio.h>

int main()
{
	int fd = open("test.txt", O_RDONLY);
	char *line;

	printf("BUFFER_SIZE: %d\n", BUFFER_SIZE);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		for (int i = 0; line[i]; i++)
			printf(" %d", line[i]);
		printf("\n");
	}
	printf("This line is attached end of line\n");
	return (0);
}
