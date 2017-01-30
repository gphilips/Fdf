/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 15:46:32 by gphilips          #+#    #+#             */
/*   Updated: 2017/01/26 18:04:33 by gphilips         ###   ########.fr       */
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

t_env		*ft_init_all(t_env *e)
{
	e->mlx = NULL;
	e->win = NULL;
	e->win_x = 1000;
	e->win_y = 500;
	e->margin_w = 150;	
	e->margin_h = 70;	
	e->file.nb_x = 0;
	e->file.nb_y = 0;
	e->file.map = NULL;
	e->file.space = 30;
	e->file.z = 10;	
	ft_init_point(e);
	return (e);
}
