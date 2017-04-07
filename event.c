/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 16:57:29 by gphilips          #+#    #+#             */
/*   Updated: 2017/02/03 19:25:11 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_change_proj(t_env *e)
{
	if (e->proj == 1)
		e->proj = 0;
	else if (e->proj == 0)
		e->proj = 1;
}

void	ft_change_depth(int key, t_env *e)
{
	if (key == PLUS)
		e->file.depth += 1;
	else if (key == MIN)
		e->file.depth -= 1;
}

void	ft_zoom(int key, t_env *e)
{
	if (key == FRONT)
		e->file.space += 5;
	else if (key == BACK && e->file.space > 5)
		e->file.space -= 5;
}

void	ft_move(int key, t_env *e)
{
	if (key == UP)
		e->margin_t -= 20;
	else if (key == DOWN)
		e->margin_t += 20;
	else if (key == LEFT)
		e->margin_l -= 20;
	else if (key == RIGHT)
		e->margin_l += 20;
}

void	ft_reinit(t_env *e)
{
	e->proj = 1;
	e->file.depth = 0;
	e->file.space = 30;
	e->margin_l = 400;
	e->margin_t = 100;
	e->color.r = 255;
	e->color.g = 255;
	e->color.b = 255;
}
