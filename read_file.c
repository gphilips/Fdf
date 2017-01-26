/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 14:53:51 by gphilips          #+#    #+#             */
/*   Updated: 2017/01/26 17:33:14 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_lst_push_back(t_list **list, char *line)
{
	while (*list != NULL)
		list = &(*list)->next;
	if (*list == NULL)
		*list = ft_lstnew(line, ft_strlen(line) + 1);
}

static int	ft_get_size(t_env *e)
{
	int		i;
	int		flag;
	char	**split;
	int		tmp_x;
	t_list	*tmp;

	flag = 0;
	tmp = e->lst;
	while (tmp)
	{
		split = ft_strsplit(tmp->content, ' ');
		i = 0;
		while (split[i])
			i++;
		if (e->file.nb_x == 0 && flag == 0)
		{
			flag = 1;
			e->file.nb_x = i;
		}
		tmp_x = i;
		if (e->file.nb_x != tmp_x)
			return (-1);
		tmp = tmp->next;
	}
	return (0);
}

void	ft_print_tab(t_env *e)
{
	printf("----- LIST ----\n");
	t_list	*temp;
	int	i;

	i = 0;
	temp = e->lst;
	while (temp)
	{
		printf("Maillon %d:\n", ++i);
		printf("%s\n", temp->content);
		temp = temp->next;
	}
	printf("Nb de col: %d\n", e->file.nb_x);
	printf("Nb de ligne: %d\n", e->file.nb_y);

	printf("----- MAP ----\n");
	int y;
	int x;

	y= -1;
	while (++y < e->file.nb_y)
	{
		x = -1;
		while (++x < e->file.nb_x)
			printf("%d  ", e->file.map[y][x]);
		printf("\n");
	}
}

int		ft_read_file(int fd, t_env *e)
{
	char	*line;
	t_list	*start;
	int		i;

	i = 0;
	e->lst = NULL;
	line = NULL;
	get_next_line(fd, &line);
	e->lst = ft_lstnew(line, ft_strlen(line) + 1);
	start = e->lst;
	free(line);
	e->file.nb_y++;
	while (get_next_line(fd, &line))
	{
		ft_lst_push_back(&e->lst, line);
		e->file.nb_y++;
		free(line);
	}
	return ((ft_get_size(e) == -1 ? -1 : 0));
}
