#include "get_next_line_bonus.h"
#include <stdio.h>

int main()
{
	int fd = open("test.txt", O_RDONLY);
	char *line;

	while (line = get_next_line(fd))
		printf("%s", line);

	return (0);
}
