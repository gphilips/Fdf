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
/*
static void			ft_center_map(t_env *e)
{
	e->map_x = (e->win_x - e->file.nb_x * e->file.w_space) / 2;
	e->map_y = (e->win_y - e->file.nb_x * e->file.nb_y) / 2;
}*/
/*
static int		ft_iso(int x, int y, int flag)
{
	int n;

	n = 0;
	if (flag == 0)
		n =	(x - y) * (e->file.w_space / 2);
	if (flag == 1)
	return (n);
}
*/
void	ft_draw_point(t_env *e)
{
	int		y;
	int		x;

	y = -1;
//	ft_center_map(e);
	while (++y < e->file.nb_y)
	{
		x = -1;
		while (++x < e->file.nb_x)
		{
			if (e->file.map[y][x] == 0)
				mlx_pixel_put(e->mlx, e->win, 250 + (x - y) * (e->file.w_space / 2), 150 + (x + y) * (e->file.h_space / 2), 0x00FFFFFF);
//				mlx_pixel_put(e->mlx, e->win, e->map_x + x * e->file.w_space, e->map_y + y * e->file.h_space, 0x00FFFFFF);
			else
				mlx_pixel_put(e->mlx, e->win, 250 + (x - y) * (e->file.w_space / 2), 150 + (x + y) * (e->file.h_space / 2), 0x0000FFFF);
//				mlx_pixel_put(e->mlx, e->win, e->map_x + x * e->file.w_space, e->map_y + y * e->file.h_space, 0x0000FFFF);
		}
		ft_draw_line(e);
	}
}
