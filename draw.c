/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 15:00:33 by gphilips          #+#    #+#             */
/*   Updated: 2017/01/27 17:59:42 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_line(t_env *e)
{
	e->point.dx = abs(e->point.x2 - e->point.x1);
	e->point.dy = abs(e->point.y2 - e->point.y1);
	e->point.sx = (e->point.x1 < e->point.x2) ? 1 : -1;
	e->point.sy = (e->point.y1 < e->point.y2) ? 1 : -1;
	e->point.err1 = e->point.dx + e->point.dy;
	while (e->point.x1 < e->point.x2 || e->point.y1 < e->point.y2)
	{
		mlx_pixel_put(e->mlx, e->win, e->point.x1, e->point.y1, 0x00FFFFFF);
		e->point.err2 = 2 * e->point.err1;
		if (e->point.err2 <= e->point.dx)
		{
			e->point.err1 += e->point.dx;
			e->point.x1 += e->point.sx;
		}
		if (e->point.err2 >= e->point.dy)
		{
			e->point.err1 += e->point.dy;
			e->point.y1 += e->point.sy;
		}
	}
}

static void		ft_iso(int x, int y, t_env *e)
{
	e->point.x1 = e->margin_x + (x - y) * (e->file.w_space / 2);
	e->point.y1 = e->margin_y + (x + y) * (e->file.h_space / 2);
}

void	ft_draw_point(t_env *e)
{
	int		y;
	int		x;

	y = -1;
	while (++y < e->file.nb_y)
	{
		x = -1;
		while (++x < e->file.nb_x)
		{
			ft_iso(x, y, e);
			if (e->file.map[y][x] == 0)
				mlx_pixel_put(e->mlx, e->win, e->point.x1, e->point.y1, 0x00FFFFFF);
//				mlx_pixel_put(e->mlx, e->win, e->map_x + x * e->file.w_space, e->map_y + y * e->file.h_space, 0x00FFFFFF);
			else
				mlx_pixel_put(e->mlx, e->win, e->point.x1, e->point.y1, 0x0000FFFF);
//				mlx_pixel_put(e->mlx, e->win, e->map_x + x * e->file.w_space, e->map_y + y * e->file.h_space, 0x0000FFFF);
		}
	}
}
/*
void	ft_draw_grid(t_env *e)
{
	int		y;
	int		x;

	y = -1;
	while (++y < e->file.nb_y)
	{
		x = -1;
		while (++x < e->file.nb_x)
		{
			ft_iso(x, y, e);
			ft_draw_line(e);
		}
	}
}*/
