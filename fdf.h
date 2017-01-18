#ifndef	FDF_H
# define FDF_H

# include "libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>

# include <stdio.h>

# define WIN_X 400
# define WIN_Y 400

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	int		file_x;
	int		file_y;
	int		x;
	int		y;
}				t_env;

void	ft_create_win(void);
void	ft_read_file(char *file);
#endif
