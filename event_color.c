#include "fdf.h"

void	ft_change_color(int key, t_env *e)
{
	if (key == RED)
		e->color.r -= 30;
	else if (key == GREEN)
		e->color.g -= 30;
	else if (key == BLUE)
		e->color.b -= 30;

}
