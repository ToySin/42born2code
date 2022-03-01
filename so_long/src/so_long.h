#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include "../libft/libft.h"

void	ft_error_occur();

int		ft_is_valid_map(char *map_data);

char	*ft_read_mapfile(int fd);

#endif