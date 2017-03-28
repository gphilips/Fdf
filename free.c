/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 17:12:39 by gphilips          #+#    #+#             */
/*   Updated: 2017/02/09 17:12:57 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_node(void *content, size_t size)
{
	free(content);
	content = NULL;
	size = 0;
}

void	ft_free_map(t_map **map, t_env *e)
{
	int		i;

	i = -1;
	while (++i < e->file.nb_y)
		free(map[i]);
	free(map);
	map = NULL;
}