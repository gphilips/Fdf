/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 15:46:19 by gphilips          #+#    #+#             */
/*   Updated: 2017/02/03 19:19:03 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_instruction(t_env *e)
{
	char	*iso;
	char	*zoom;
	char	*move;
	char	*proj;
	char	*reinit;

	iso = "P = increase the depth\n | L = lower the depth\n";
	zoom = "F = zoom in\n | B = zoom out";
	move = "UP | DOWN | LEFT | RIGHT = move the map\n";
	proj = "TAB = change the projection of the map\n";
	reinit = "ENTER = reinitialise the map\n";
	mlx_string_put(e->mlx, e->win, 10, 0, 0x00FFFFFF, "COMMANDS:");
	mlx_string_put(e->mlx, e->win, 10, 20, 0x00FFFFFF, iso);
	mlx_string_put(e->mlx, e->win, 10, 40, 0x00FFFFFF, zoom);
	mlx_string_put(e->mlx, e->win, 10, 60, 0x00FFFFFF, move);
	mlx_string_put(e->mlx, e->win, 10, 80, 0x00FFFFFF, proj);
	mlx_string_put(e->mlx, e->win, 10, 100, 0x00FFFFFF, reinit);
}

static int	mouse_hook(int button, int x, int y)
{
	ft_putstr("Mouse ");
	ft_putnbr(button);
	ft_putstr(": x: ");
	ft_putnbr(x);
	ft_putstr(" | y: ");
	ft_putnbr(y);
	ft_putchar('\n');
	return (0);
}

static int	key_hook(int keycode, t_env *e)
{
	ft_putstr("key: ");
	ft_putnbr(keycode);
	ft_putchar('\n');
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
	ft_instruction(e);
	mlx_key_hook(e->win, key_hook, e);
	mlx_mouse_hook(e->win, mouse_hook, e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_loop(e->mlx);
}
