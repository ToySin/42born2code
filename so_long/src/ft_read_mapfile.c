#include "so_long.h"

static char	*ft_string_adder(char *s1, char *s2);

char	*ft_read_mapfile(int fd)
{
	char	buf[1025];
	char	*save;
	int		rbyte;

	rbyte = 1;
	while (rbyte > 0)
	{
		rbyte = read(fd, buf, 1024);
		// file open error
		if (rbyte == -1)
			exit(1);
		buf[rbyte] = '\0';
		save = ft_string_adder(save, buf);
		if (!save)
			break ;
	}
	return (save);
}

char	*ft_string_adder(char *s1, char *s2)
{
	int		s1_len;
	int		s2_len;
	char	*comb;

	if (!s1)
		return (ft_strdup(s2));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	comb = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!comb)
	{
		free(s1);
		return (0);
	}
	ft_strlcpy(comb, s1, s1_len + 1);
	ft_strlcat(comb + s1_len, s2, s2_len + 1);
	free(s1);
	return (comb);
}