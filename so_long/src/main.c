#include "so_long.h"

int	main(void)
{
	int		fd;
	char	*map;
	
	fd = open("resource/map_file.ber", O_RDONLY);
	ft_putnbr_fd(fd, 1);
	ft_putchar_fd('\n', 1);
	map = ft_read_mapfile(fd);
	ft_putstr_fd(map, 1);
	free(map);
	system("leaks so_long > leaks_result; cat leaks_result | grep leaked && rm -rf leaks_result");
	return (0);
}