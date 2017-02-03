/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 15:46:32 by gphilips          #+#    #+#             */
/*   Updated: 2017/02/03 16:00:01 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_init_point(t_env *e)
{
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
	e->file.map = NULL;
	e->file.space_w = 30;
	e->file.space_h = 15;
	e->file.depth = 10;
}

t_env		*ft_init_all(t_env *e)
{
	e->mlx = NULL;
	e->win = NULL;
	e->win_x = 1000;
	e->win_y = 600;
	e->margin_l = 0;
	e->margin_t = 0;
	e->proj = 1;
	ft_init_point(e);
	ft_init_file(e);
	return (e);
}
