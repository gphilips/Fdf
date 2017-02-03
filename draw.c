/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 15:00:33 by gphilips          #+#    #+#             */
/*   Updated: 2017/02/03 16:49:17 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_pixel_put(t_env *e, t_map p1, t_map p2)
{
	int		color;

	color = (p1.z == 0 && p2.z == 0) ? 0x00FFFFFF : 0x0000FFFF;
	mlx_pixel_put(e->mlx, e->win, p1.x, p1.y, color);
}

static void		ft_draw_line(t_env *e, t_map p1, t_map p2)
{
	e->point.dx = abs(p2.x - p1.x);
	e->point.dy = abs(p2.y - p1.y);
	e->point.sx = (p1.x < p2.x) ? 1 : -1;
	e->point.sy = (p1.y < p2.y) ? 1 : -1;
	e->point.err1 = (e->point.dx > e->point.dy ? e->point.dx : -e->point.dy) / 2;
	while (1)
	{
		ft_pixel_put(e, p1, p2);
		if (p1.x == p2.x && p1.y == p2.y)
			break ;
		e->point.err2 = e->point.err1;
		if (e->point.err2 >= -e->point.dx)
		{
			e->point.err1 -= e->point.dy;
			p1.x += e->point.sx;
		}
		if (e->point.err2 <= e->point.dy)
		{
			e->point.err1 += e->point.dx;
			p1.y += e->point.sy;
		}
	}
}

static void	ft_3d(t_env *e)
{
	int		y;
	int		x;

	y = 0;
	while (++y < e->file.nb_y)
	{
		x = 0;
		while (++x < e->file.nb_x)
		{
			if ((e->file.map[y][x - 1].z == 0 && e->file.map[y][x].z > 0)
				|| (e->file.map[y][x + 1].z == 0 && e->file.map[y][x].z > 0)
				|| (e->file.map[y][x + 1].z > 0 && e->file.map[y][x].z > 0))
			{
				e->file.map[y][x].x -= (e->file.map[y][x].z + e->file.depth) / 2;
				e->file.map[y][x].y -= (e->file.map[y][x].z + e->file.depth) / 2;
			}
		}
	}
}

void		ft_draw_grid(t_env *e)
{
	int		y;
	int		x;

	ft_3d(e);
	y = -1;
	while (++y < e->file.nb_y)
	{
		x = -1;
		while (++x < e->file.nb_x)
		{
			if (x < e->file.nb_x - 1)
			{
				ft_draw_line(e, e->file.map[y][x], e->file.map[y][x + 1]);
			}
			if (y < e->file.nb_y - 1)
				ft_draw_line(e, e->file.map[y][x], e->file.map[y + 1][x]);
		}
	}
}
