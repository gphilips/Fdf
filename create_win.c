/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 15:46:19 by gphilips          #+#    #+#             */
/*   Updated: 2017/01/26 18:24:09 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	mouse_hook(int button, int x, int y)
{
	printf("Mouse: %d (x: %d | y: %d)\n", button, x, y);
	return (0);
}

static int	key_hook(int keycode, t_env *e)
{
	printf("key: %d\n", keycode);
	if (keycode == 53)
		exit(0);
	if (keycode == 48 && e->proj == 1)
		e->proj = 0;
	else if (keycode == 48 && e->proj == 0)
		e->proj = 1;
	if (keycode == 44)
		e->file.depth += 5;
	if (keycode == 24)
		e->file.depth -= 5;
	if (keycode == 36)
	{
		e->proj = 1;
		e->file.depth = 0;
	}
	return (0);
}
/*
int			expose_hook(t_env *e)
{
	e->img = mlx_new_image(e->mlx, e->win_x, e->win_y);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	ft_draw_grid(e);
	mlx_destroy_image(e->mlx, e->img);
	return (0);
}
*/
void		ft_create_win(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, e->win_x, e->win_y, "fdf");
	mlx_key_hook(e->win, key_hook, &e);
	mlx_mouse_hook(e->win, mouse_hook, &e);
	ft_draw_grid(e);
	//mlx_expose_hook(e->win, expose_hook, &e);
	mlx_loop(e->mlx);
}
