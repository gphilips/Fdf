/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 15:46:32 by gphilips          #+#    #+#             */
/*   Updated: 2017/01/27 18:18:59 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_init_point(t_env *e)
{
	e->point.x1 = 0;
	e->point.y1 = 0;
	e->point.x2 = 0;
	e->point.x2 = 0;
	e->point.dx = 0;
	e->point.dy = 0;
	e->point.sx = 0;
	e->point.sy = 0;
	e->point.err1 = 0;
	e->point.err2 = 0;
}

static void	ft_init_file(t_env *e)
{
	e->file.nb_x = 0;
	e->file.nb_y = 0;
	e->file.map.w = 0;
	e->file.map.y = 0;
	e->file.map.z = 0;
	e->file.w_space = 25;
	e->file.h_space = 25;
}

t_env		*ft_init_all(t_env *e)
{
	e->mlx = NULL;
	e->win = NULL;
	e->win_x = 600;
	e->win_y = 600;
	e->margin_x = 250;
	e->margin_y = 150;
	ft_init_file(e);
	ft_init_point(e);
	return (e);
}
