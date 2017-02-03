/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 15:46:19 by gphilips          #+#    #+#             */
/*   Updated: 2017/02/03 18:35:30 by gphilips         ###   ########.fr       */
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
	if (keycode == ESC)
		exit(0);
	else if (keycode == TAB)
		ft_change_proj(e);
	else if (keycode == PLUS || keycode == MIN)
		ft_change_depth(keycode, e);
	else if (keycode == FRONT || keycode == BACK)
		ft_zoom(keycode, e);
	else if (keycode == UP || keycode == DOWN
			|| keycode == LEFT || keycode == RIGHT)
		ft_move(keycode, e);
	else if (keycode == ENT)
		ft_reinit(e);
//	mlx_clear_window(e->mlx, e->win);
//	ft_draw_grid(e);
	return (0);
}

int			expose_hook(t_env *e)
{
	ft_draw_grid(e);
	return (0);
}

void		ft_create_win(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, e->win_x, e->win_y, "fdf");
	mlx_key_hook(e->win, key_hook, e);
	mlx_mouse_hook(e->win, mouse_hook, e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_loop(e->mlx);
}
