/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 16:57:29 by gphilips          #+#    #+#             */
/*   Updated: 2017/02/03 18:37:23 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_change_proj(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	if (e->proj == 1)
		e->proj = 0;
	else if (e->proj == 0)
		e->proj = 1;
	ft_create_int_tab(e->lst, e);
	ft_draw_grid(e);
}

void	ft_change_depth(int key, t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	if (key == PLUS)
		e->file.depth -= 5;
	else if (key == MIN)
		e->file.depth += 5;
	ft_create_int_tab(e->lst, e);
	ft_draw_grid(e);
}

void	ft_zoom(int key, t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	if (key == FRONT)
	{
		e->file.space_w += 5;
		e->file.space_h += 5;
	}
	else if (key == BACK)
	{
		e->file.space_w -= 5;
		e->file.space_h -= 5;
	}
	ft_create_int_tab(e->lst, e);
	ft_draw_grid(e);
}

void	ft_move(int key, t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	if (key == UP)
		e->margin_t -= 5;
	if (key == DOWN)
		e->margin_t += 5;
	if (key == LEFT)
		e->margin_l -= 5;
	if (key == RIGHT)
		e->margin_l -= 5;
	ft_create_int_tab(e->lst, e);
	ft_draw_grid(e);
}

void	ft_reinit(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	e->proj = 1;
	e->file.depth = 0;
	ft_create_int_tab(e->lst, e);
	ft_draw_grid(e);
}
