#ifndef	FDF_H
# define FDF_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>

# include <stdio.h>

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	char	**map;
	int		x;
	int		y;
	int		z;
}				t_env;

void	ft_create_win(void);
void	ft_create_grid(void);
#endif
