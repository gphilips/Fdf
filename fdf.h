#ifndef	FDF_H
# define FDF_H

# include "libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>

# include <stdio.h>
/*
typedef struct	s_color
{
	int			color;
	int			red;
	int			green;
	int			blue;
}				t_color;
*/

typedef struct	s_file
{
	int			**map;
	char		**split;
	int			x;
	int			y;
}				t_file;

typedef struct	s_point
{
	int			x1;
	int			y1;
	int			x2;
	int			y2;
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			err1;
	int			err2;
}				t_point;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	int			win_x;
	int			win_y;
	t_file		file;
	t_list		*lst;
	t_point		point;
//	t_color		color;
}				t_env;

t_env	*ft_init_all(t_env *e);
void	ft_read_file(int fd, t_env *e);
int		**ft_create_int_tab(t_list *lst, t_env *e);
void	ft_create_win(t_env *e);
#endif
