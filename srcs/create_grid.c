#include "../include/fdf.h"

void	ft_create_grid(char *map)
{
	t_env	e;
	int		i;
	int		j;

	j = 0;
	while (map[j] != '\0')
	{
		i = 0;
		while (map[j][i] == 0 && map[j][i] != '\n')
		{
			if (map[i] == 0)
				mlx_pixel_put(e.mlx, e.win, e.x, e.y, 0xFFFFFF);
			i++;
		}
		j++;
	}
}
