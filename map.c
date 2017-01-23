#include "fdf.h"

int		**ft_create_int_tab(t_list *lst, t_env *e)
{
	int		**tab;
	int		x;
	int		y;
	
	tab = (int**)ft_memalloc(sizeof(int*) * e->file.y);
	y = -1;
	while (++y < e->file.y)
	{
		e->file.tabsplit = ft_strsplit((char*)lst->content, ' ');
		tab[y] = (int*)ft_memalloc(sizeof(int) * e->file.x);
		x = -1;
		while (++x < e->file.x)
		{
//			printf("tabsplit: %s\n", e->file.tabsplit[x]);
//			printf("tabsplit atoi: %d\n", ft_atoi(e->file.tabsplit[x]));
			tab[y][x] = ft_atoi(e->file.tabsplit[x]);
//			printf("%d\n", tab[0][0]);
			free(e->file.tabsplit[x]);
		}
		lst = lst->next;
	}
	free(e->file.tabsplit);
	return (tab);
}
