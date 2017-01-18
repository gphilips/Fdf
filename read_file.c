#include "fdf.h"

static void	ft_lst_push_back(t_list **list, char *line)
{
	while (*list != NULL)
		list = &(*list)->next;
	if (*list == NULL)
		*list = ft_lstnew(line, ft_strlen(line) + 1);
}

void		ft_read_file(char *file)
{
	int		fd;
	char	*line;
	int		nb_line;
	t_list	*lst;

	fd = open(file, O_RDONLY);
	lst = NULL;
	nb_line = 0;
	while (get_next_line(fd, &line))
	{
		ft_lst_push_back(&lst, line);
		nb_line++;
	}

	printf("-----TEST----\n");	
	t_list	*tmp;
	int	i = 0;
	
	tmp = lst;
	while (tmp)
	{
		printf("Maillon %d:\n", ++i);
		printf("%s\n", tmp->content);
		printf("Content size: %zu\n", tmp->content_size);
		tmp = tmp->next;
	}
	printf("Nb de ligne: %d\n", nb_line);
}
