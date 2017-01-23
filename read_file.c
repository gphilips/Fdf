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
	t_list	*tmp;

	i = 0;
	tmp = e->lst;
	while (tmp)
	{
		e->file.split = ft_strsplit(tmp->content, ' ');
		while (e->file.split[i])
			i++;
		if (e->file.x == 0)
			e->file.x = i;
		if (e->file.x != i)
			return (-1);
		tmp = tmp->next;
	}
	return (0);
}

/* Affichage du contenu de list et de la map */

static void		ft_print_tab(t_env *e)
{
	printf("-----LIST----\n");	
	t_list	*temp;
	int	i = 0;
	
	temp = e->lst;
	while (temp)
	{
		printf("Maillon %d:\n", ++i);
		printf("%s\n", temp->content);
		temp = temp->next;
	}
	printf("Nb de col: %d\n", e->file.x);
	printf("Nb de ligne: %d\n", e->file.y);
	
	printf("-----MAP----\n");
	int y = -1;
	int x;
	while (++y < e->file.y)
	{
		x = -1;
		while (++x < e->file.x)
			printf("%d  ", e->file.map[y][x]);
		printf("\n");
	}
}

void	ft_read_file(int fd, t_env *e)
{
	char	*line;
	t_list	*start;
	
	e->lst = NULL;
	line = NULL;
	get_next_line(fd, &line);
	e->lst = ft_lstnew(line, ft_strlen(line) + 1);
	start = e->lst;
	free(line);
	e->file.y++;
	ft_get_size(e);
	while (get_next_line(fd, &line))
	{
		ft_lst_push_back(&e->lst, line);
		e->file.y++;
		free(line);
	}
	e->file.map = ft_create_int_tab(e->lst, e);
	ft_print_tab(e);
}
