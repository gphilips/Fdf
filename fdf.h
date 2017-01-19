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
	void		*mlx;
	void		*win;
	int			win_x;
	int			win_y;
}				t_env;
/*
typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;
*/
typedef struct	s_file
{
	int			**map;
	int			file_x;
	int			file_y;
}				t_file;

int		ft_create_fdf(char *file);
void	ft_read_file(int fd, t_file *file);
int		**ft_create_map(t_list *start, t_file *map);
void	ft_create_win(t_env *e);
#endif
