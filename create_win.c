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

static int		mouse_hook(int button, int x, int y)
{
	printf("Mouse: %d (x: %d | y: %d)\n", button, x, y);
	return (0);
}

static int		key_hook(int keycode)
{
	printf("key: %d\n", keycode);
	if (keycode == 53)
		exit(0);
	return (0);
}

void			ft_create_win(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, e->win_x, e->win_y, "fdf");
	ft_draw_point(e);
//	ft_draw_line(e);
	mlx_key_hook(e->win, key_hook, &e);
	mlx_mouse_hook(e->win, mouse_hook, &e);
	mlx_loop(e->mlx);
}
