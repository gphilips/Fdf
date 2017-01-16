#include "../include/fdf.h"

static int		mouse_hook(int button, int x, int y)
{
	printf("Mouse: %d (x: %d | y: %d)\n", button, x, y);
	return (0);
}

static int		key_hook(int keycode)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

void			ft_create_win(void)
{
	t_env	e;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 400, 400, "fdf");
	mlx_key_hook(e.win, key_hook, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_loop(e.mlx);
}
