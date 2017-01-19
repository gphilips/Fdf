#include "fdf.h"

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putendl("Usage: ./fdf <filename> [ case_size z_size ]");
		return (0);
	}
	ft_create_fdf(argv[1]);
	return (0);
}
