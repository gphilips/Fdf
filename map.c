/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 15:47:44 by gphilips          #+#    #+#             */
/*   Updated: 2017/02/09 17:15:52 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_iso(t_env *e, int x, int y)
{
	t_file	f;

	f = e->file;
	if (e->proj == 1)
	{
		f.map[y][x].x = e->margin_l + (x - y) * (f.space / 2);
		f.map[y][x].y = e->margin_t + (x + y) * (f.space / 2) - (f.map[y][x].z * f.depth);
	}
	if (e->proj == 0)
	{
		f.map[y][x].x = e->margin_l + (x * f.space);
		f.map[y][x].y = e->margin_t + (y * f.space) - (f.map[y][x].z * f.depth);
	}
}

t_map		**ft_create_int_tab(t_list *lst, t_env *e)
{
	int		x;
	int		y;
	t_list	**start;

	start = &lst;
	e->file.map = (t_map**)ft_memalloc(sizeof(t_map*) * e->file.nb_y);
	y = -1;
	while (++y < e->file.nb_y)
	{
		e->file.split = ft_strsplit((char*)lst->content, ' ');
		e->file.map[y] = (t_map*)ft_memalloc(sizeof(t_map) * e->file.nb_x);
		x = -1;
		while (++x < e->file.nb_x)
		{
			e->file.map[y][x].z = ft_atoi(e->file.split[x]);
			ft_iso(e, x, y);
			free(e->file.split[x]);
		}
		lst = lst->next;
	}
	free(e->file.split);
	ft_lstdel(start, ft_free_node);
	return (e->file.map);
}
