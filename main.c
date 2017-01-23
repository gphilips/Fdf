#include "fdf.h"

static int	ft_error(int n)
{
	if (n == 1)
		ft_putendl("usage: ./fdf <filename> [ case_size z_size ]");
	if (n == 2)
		ft_putendl("error: something is wrong with the file");
	if (n == 3)
		ft_putendl("error: bad size of the file");
	return (-1);
}

int			main(int argc, char **argv)
{
	t_env	*e;
	int		fd;
	
	e = (t_env*)ft_memalloc(sizeof(t_env));
	if (argc != 2)
		ft_error(1);
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		ft_error(2);
	e = ft_init_all(e);
	ft_read_file(fd, e);
//	ft_create_win(e);
	if ((close(fd)) == -1)
		ft_error(2);
	return (0);
}
