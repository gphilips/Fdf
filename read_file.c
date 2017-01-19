#include "fdf.h"

static void	ft_lst_push_back(t_list **list, char *line)
{
	while (*list != NULL)
		list = &(*list)->next;
	if (*list == NULL)
		*list = ft_lstnew(line, ft_strlen(line) + 1);
}

void	ft_read_file(int fd, t_file *file)
{
	char	*line;
	t_list	*lst;
	t_list	*start;
	
	lst = NULL;
	file->file_x = 0;
	file->file_y = 0;
	get_next_line(fd, &line);
	lst = ft_lstnew(line, ft_strlen(line));
	free(line);
	file->file_y++;
	start = lst;
	while (get_next_line(fd, &line))
	{
		ft_lst_push_back(&start, line);
		file->file_x = ft_count_word(line, ' ');
		file->file_y++;
		free(line);
	}
	file->map = ft_create_map(start, file);
	
	printf("-----LIST----\n");	
	t_list	*temp;
	int	i = 0;
	
	temp = lst;
	while (temp)
	{
		printf("Maillon %d:\n", ++i);
		printf("%s\n", temp->content);
		temp = temp->next;
	}
	printf("Nb de col: %d\n", file->file_x);
	printf("Nb de ligne: %d\n", file->file_y);
	printf("\n-----MAP----\n");
//	i = 0;
//	int j = 0;
	printf("%d", file->map[1][2]);
/*	while (*file->map[j++])
	{
		while (file->map[j][i++])
			printf("%d", *file->map[j]);
	}*/
}
