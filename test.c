#include "get_next_line.h"
#include <stdio.h>

int main()
{
	int fd = open("test.txt", O_RDONLY);
	char *line;

	for (int i = 0; i < 5; i++)
	{
		printf("%s\n", get_next_line(fd));
	}

	printf("%s\n%s\n", ft_strjoin("\0", "buf"), ft_strjoin("save", "\0"));
	return (0);
}
