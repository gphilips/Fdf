/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 15:47:44 by gphilips          #+#    #+#             */
/*   Updated: 2017/12/22 19:58:30 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Je creer une projection isometriaue, c'est une formule que jai trouve sur
// internet et ai implemente. En gros, c'est ce qui donne l'impression que la
// camera est legerement decale face a la map
// si la variable e->proj vaut 1 alors l'effet isometriaue est applique
// sinon cest la projection standards en 2D
static void	ft_iso(t_env *e, int x, int y)
{
	t_file	f;
	float	change_z;

	f = e->file;
	change_z = f.map[y][x].z * f.depth;
	if (e->proj == 1)
	{
		f.map[y][x].x = e->margin_l + (x - y) * (f.space / 2);
		f.map[y][x].y = e->margin_t + (x + y) * (f.space / 2) - change_z;
	}
	if (e->proj == 0)
	{
		f.map[y][x].x = e->margin_l + (x * f.space);
		f.map[y][x].y = e->margin_t + (y * f.space) - change_z;
	}
}

//Je stocke chaque nombre dans un tableau d'int
t_map		**ft_create_int_tab(t_list *lst, t_env *e)
{
	int		x;
	int		y;
	t_list	**start;

	start = &lst;
	if (!(e->file.map = (t_map**)ft_memalloc(sizeof(t_map*) * e->file.nb_y)))
		return (NULL);
	y = -1;
	while (++y < e->file.nb_y)
	{
		e->file.split = ft_strsplit((char*)lst->content, ' ');
		if (!(e->file.map[y] = (t_map*)ft_memalloc(sizeof(t_map)
			* e->file.nb_x)))
			return (NULL);
		x = -1;
		while (++x < e->file.nb_x)
		{
			e->file.map[y][x].z = ft_atoi(e->file.split[x]);
			ft_iso(e, x, y);
			ft_strdel(&e->file.split[x]);
		}
		ft_tabdel(e->file.split);
		lst = lst->next;
	}
	ft_lstdel(start, ft_free_node);
	return (e->file.map);
}
