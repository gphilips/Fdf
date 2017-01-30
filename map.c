/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 15:47:44 by gphilips          #+#    #+#             */
/*   Updated: 2017/01/26 17:42:51 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	**ft_create_int_tab(t_list *lst, t_env *e)
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
			free(split[x]);
//			printf("split: %s\n", split[x]);
//			printf("split atoi: %d\n", ft_atoi(split[x]));
			e->file.map[y][x].x = x * e->file.space;
			e->file.map[y][x].y = y * e->file.space;
			e->file.map[y][x].z = ft_atoi(split[x]);
//			printf("%d\n", e->map[0][0]);
		}
		lst = lst->next;
	}
	free(split);
	return (e->file.map);
}
