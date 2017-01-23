#include "fdf.h"

static void	ft_error(int n)
{
	if (n == 1)
		ft_putendl("usage: ./fdf <filename> [ case_size z_size ]");
	if (n == 2)
		ft_putendl("error: the file doesn't exist");
}

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_error(1);
		return (0);
	}
	if (ft_create_fdf(argv[1]) == -1)
		ft_error(2);
	return (0);
}
