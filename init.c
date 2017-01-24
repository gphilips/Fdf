/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 15:46:32 by gphilips          #+#    #+#             */
/*   Updated: 2017/01/24 15:46:33 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_env	*ft_init_all(t_env *e)
{
	e->win_x = 400;
	e->win_y = 400;
	e->mlx = NULL;
	e->win = NULL;
	e->file.x = 0;
	e->file.y = 0;
	e->file.map = 0;
	e->file.split = NULL;
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
	return (e);
}
