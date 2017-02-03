/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 15:47:44 by gphilips          #+#    #+#             */
/*   Updated: 2017/02/03 18:01:18 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_iso(t_env *e, int x, int y)
{
	if (e->proj == 1)
	{
		e->margin_l = (e->win_x / 4) * 2;
		e->margin_t = (e->win_y / 4) * 2;
		e->file.map[y][x].x = e->margin_l + (x - y) * (e->file.space_w / 2);
		e->file.map[y][x].y = e->margin_t + (x + y) * (e->file.space_h / 2);
	}
	if (e->proj == 0)
	{
		e->margin_l = (e->win_x / 2) / 2;
		e->margin_t = (e->win_y / 4);
		e->file.map[y][x].x = e->margin_l + x * e->file.space_w;
		e->file.map[y][x].y = e->margin_t + y * e->file.space_h;
	}
}

t_map		**ft_create_int_tab(t_list *lst, t_env *e)
{
	char	**split;
	int		x;
	int		y;

	e->file.map = (t_map**)ft_memalloc(sizeof(t_map*) * e->file.nb_y);
	y = -1;
	while (++y < e->file.nb_y)
	{
		split = ft_strsplit((char*)lst->content, ' ');
		e->file.map[y] = (t_map*)ft_memalloc(sizeof(t_map) * e->file.nb_x);
		x = -1;
		while (++x < e->file.nb_x)
		{
			e->file.map[y][x].z = ft_atoi(split[x]);
			ft_iso(e, x, y);
			free(split[x]);
		}
		lst = lst->next;
	}
	free(split);
	return (e->file.map);
}
