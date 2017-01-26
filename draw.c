/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 15:00:33 by gphilips          #+#    #+#             */
/*   Updated: 2017/01/26 18:38:59 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_line(t_env *e)
{
	int		x;
	int		y;

	x = e->point.x1;
	y = e->point.y1;
	e->point.dx = abs(e->point.x2 - e->point.x1);
	e->point.dy = abs(e->point.y2 - e->point.y1);
	e->point.sx = (e->point.x1 < e->point.x2) ? -1 : 1;
	e->point.sy = (e->point.y1 < e->point.y2) ? -1 : 1;
	if (e->point.dx > e->point.dy)
	{
		while (x < e->point.x2)
		{
			mlx_pixel_put(e->mlx, e->win, e->point.x1, e->point.y1, 0x00FFFFFF);
			e->point.err1 += e->point.dx;
			if (e->point.err1 > e->point.dx / 2)
			{
				e->point.err1 -= e->point.dx;
				y += e->point.sy;
			}
			x += e->point.sx;
		}
	}
	else
	{
		while (y < e->point.y2)
		{
			mlx_pixel_put(e->mlx, e->win, e->point.x1, e->point.y1, 0x00FFFFFF);
			e->point.err2 += e->point.dy;
			if (e->point.err2 >e->point.dy / 2)
			{
				e->point.err2 -= e->point.dy;
				x += e->point.sx;
			}
			y += e->point.sy;
		}
	}
}
/*
static int		ft_iso(int x, int y)
{
	int n;

	n = 0;
	if ()
		n =	(x - y) * (e->file.w_space / 2);
	return (n);
}
*/
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
			if (e->file.map[y][x] == 0)
				mlx_pixel_put(e->mlx, e->win, (x - y) * (e->file.w_space / 2), (x + y) * (e->file.h_space / 2), 0x00FFFFFF);
			else
				mlx_pixel_put(e->mlx, e->win, (x - y) * (e->file.w_space / 2), (x + y) * (e->file.h_space / 2), 0x0000FFFF);
		}
	}
}
