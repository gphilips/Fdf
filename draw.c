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

static void		ft_pixel_put(t_env *e, t_map p1, t_map p2)
{
	int		color;

	color = (p1.z == 0 && p2.z == 0) ? 0x00FFFFFF : 0x0000FFFF;
	mlx_pixel_put(e->mlx, e->win, p1.x, p1.y, color);
}

static void		ft_draw_line(t_env *e, t_map p1, t_map p2)
{
	t_point		p;
	
	p = e->point;
	p.dx = abs(p2.x - p1.x);
	p.dy = abs(p2.y - p1.y);
	p.sx = (p1.x < p2.x) ? 1 : -1;
	p.sy = (p1.y < p2.y) ? 1 : -1;
	p.err1 = (p.dx > p.dy ? p.dx : -p.dy) / 2;
	while (p1.x <= p2.x && p1.y <= p2.y)
	{
		ft_pixel_put(e, p1, p2);
		p.err2 = p.err1;
		if (p.err2 > -p.dx)
		{
			p.err1 -= p.dy;
			p1.x += p.sx;
		}
		if (p.err2 < p.dy)
		{
			p.err1 += p.dx;
			p1.y += p.sy;
		}
	}
}

void			ft_draw_grid(t_env *e)
{
	int		y;
	int		x;

	y = -1;
	while (++y < e->file.nb_y)
	{
		x = -1;
		while (++x < e->file.nb_x)
		{
			if (x < e->file.nb_x - 1)
				ft_draw_line(e, e->file.map[y][x], e->file.map[y][x + 1]);
			if (y < e->file.nb_y - 1)
				ft_draw_line(e, e->file.map[y][x], e->file.map[y + 1][x]);
		}
	}

}
