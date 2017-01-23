#include "fdf.h"

int		ft_create_fdf(char *argv)
{
	t_env	e;
	int		fd;

	if ((fd = open(argv, O_RDONLY)) < 0)
		return (-1);
	ft_read_file(fd, &e);
//	ft_create_int_tab();
//	ft_create_win(&e);
	if (close(fd) == -1)
		return (-1);
	return (0);
}
