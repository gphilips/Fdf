#include "fdf.h"

int		**ft_create_map(t_list *start, t_file *file)
{
	char	*line;
	char	**tmp;
	int		x;
	int		y;

	if (!(file->map = (int**)malloc(sizeof(int*) * file->file_y)))
		return (NULL);
	line = start->content;
	y = 0;
	while (y < file->file_y)
	{
		if (!(file->map[y] = (int*)malloc(sizeof(int) * file->file_x)))
		return(NULL);
		tmp = ft_strsplit(line, ' ');
		x = 0;
		while (x < file->file_x)
		{
			file->map[y][x] = ft_atoi(tmp[x]);
			x++;
		}
		y++;
		start = start->next;
	}
	return (file->map);
}
