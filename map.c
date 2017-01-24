/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 15:47:44 by gphilips          #+#    #+#             */
/*   Updated: 2017/01/24 15:51:11 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		**ft_create_int_tab(t_list *lst, t_env *e)
{
	int		**tab;
	char	**split;
	int		x;
	int		y;

	tab = (int**)ft_memalloc(sizeof(int*) * e->file.y);
	y = -1;
	while (++y < e->file.y)
	{
		split = ft_strsplit((char*)lst->content, ' ');
		tab[y] = (int*)ft_memalloc(sizeof(int) * e->file.x);
		x = -1;
		while (++x < e->file.x)
		{
			free(split[x]);
//			printf("split: %s\n", split[x]);
//			printf("split atoi: %d\n", ft_atoi(split[x]));
			tab[y][x] = ft_atoi(split[x]);
//			printf("%d\n", tab[0][0]);
		}
		lst = lst->next;
	}
	free(split);
	return (tab);
}
