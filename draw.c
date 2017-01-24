/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 15:00:33 by gphilips          #+#    #+#             */
/*   Updated: 2017/01/24 18:06:54 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_point(t_env *e)
{
	int		y;
	int		x;

	y = -1;
	while ((y += 3) < (e->file.y + 10 * 10))
	{
		printf("y: %d - x: %d\n", e->file.y, e->file.x);
		x = -1;
		while ((x += 3) < (e->file.x + 10 * 18))
		{
			if (e->file.map[y][x] == 0)
					mlx_pixel_put(e->mlx, e->win, x, y, 0x00FFFFFF);
			else
					mlx_pixel_put(e->mlx, e->win, x, y, 0x0000FFFF);
		}
	}
}
