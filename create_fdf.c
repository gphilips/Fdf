#include "fdf.h"

int		ft_create_fdf(char *argv)
{
//	t_env	e;
	t_file	file;
	int		fd;

	fd = open(argv, O_RDONLY);
	ft_read_file(fd, &file);
//	ft_create_map();
//	ft_create_win(&e);
	if (close(fd) == -1)
		return (-1);
	return (0);
}
