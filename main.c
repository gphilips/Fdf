#include "fdf.h"

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putendl("Usage: ./fdf <filename> [ case_size z_size ]");
		return (0);
	}
	ft_read_file(argv[1]);
	//ft_create_win();
	return (0);
}
