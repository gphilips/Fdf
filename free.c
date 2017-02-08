#include "fdf.h"

void	ft_free_node(void *content, size_t size)
{
	free(content);
	content = NULL;
	size = 0;
}

void	ft_free_split(char **split, t_env *e)
{
	int		i;

	i = -1;
	while (++i < e->file.nb_y)
		free(split[i]);
	free(split);
	split = NULL;
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
