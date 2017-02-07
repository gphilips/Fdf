/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 15:00:33 by gphilips          #+#    #+#             */
/*   Updated: 2017/02/03 18:59:18 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_color_depth(t_env *e, t_map p1, t_map p2)
{
	int		color;

	if (p1.z == 0 && p2.z == 0)
	{
		e->color.r = 255;
		e->color.g = 255;
		e->color.b = 255;
	}
	else if ((p1.z != 0 || p2.z != 0) && e->file.depth < -10)
	{
		e->color.r = 0;
		e->color.g = 33;
		e->color.b = 99;
//	color = 0x00003399;
	}
	else if (p1.z == 0 && p2.z != 0)
	{
		e->color.r = 0;
		e->color.g = 33;
		e->color.b = 99;
//	color = 0x00003399;
	}
	else
	{
		e->color.r = 33;
		e->color.g = 99;
		e->color.b = FF;
//		color = 0x003399FF;
	}
}

static void		ft_pixel_put(t_env *e, t_map p1, t_map p2)
{
	int		i;

	if ((p1.x > 0 && p1.x < e->win_x) && (p1.y > 0 && p1.y < e->win_y))
	{
		i = (p1.y * e->sizeline) + (p1.x * e->bpp / 8);
		e->data[i] = e->color.r;
		e->data[i + 1] = e->color.g;
		e->data[i + 2] = e->color.b;
	}
	ft_color_depth(e, p1, p2);

}

static void		ft_draw_line(t_env *e, t_map p1, t_map p2)
{
	e->point.dx = abs(p2.x - p1.x);
	e->point.dy = abs(p2.y - p1.y);
	e->point.sx = (p1.x < p2.x) ? 1 : -1;
	e->point.sy = (p1.y < p2.y) ? 1 : -1;
	e->point.err1 = (e->point.dx > e->point.dy ? e->point.dx : -e->point.dy) / 2;
	while (p1.x != p2.x || p1.y != p2.y)
	{
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
		ft_pixel_put(e, p1, p2);
	}
}

static void	ft_3d(t_env *e)
{
	int		y;
	int		x;
	t_file	f;

	f = e->file;
	y = -1;
	while (++y < e->file.nb_y)
	{
		x = -1;
		while (++x < e->file.nb_x)
		{
			if (f.map[y][x].z > 0)
			{
				f.map[y][x].x -= (f.map[y][x].z + f.depth) / f.nb_x;
				f.map[y][x].y -= (f.map[y][x].z + f.depth) * f.nb_y;
			}
			else if (f.map[y][x].z < 0)
			{
				f.map[y][x].x += (f.map[y][x].z + f.depth) / f.nb_x;
				f.map[y][x].y += (f.map[y][x].z + f.depth) * f.nb_y;
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
