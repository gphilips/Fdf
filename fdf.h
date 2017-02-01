/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 14:53:54 by gphilips          #+#    #+#             */
/*   Updated: 2017/01/26 18:02:55 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FDF_H
# define FDF_H

# include "libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>

# include <stdio.h>

typedef struct	s_map
{
	int			x;
	int			y;
	int			z;
}				t_map;

typedef struct	s_file
{
	t_map		**map;
	int			nb_x;
	int			nb_y;
	int			space_w;
	int			space_h;
	int			depth;
}				t_file;

typedef struct	s_point
{
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
	void		*img;
	int			win_x;
	int			win_y;
	int			margin_l;
	int			margin_t;
	int			proj;
	t_file		file;
	t_list		*lst;
	t_point		point;
}				t_env;

t_env	*ft_init_all(t_env *e);
int		ft_read_file(int fd, t_env *e);
t_map	**ft_create_int_tab(t_list *lst, t_env *e);
void	ft_print_tab(t_env *e); // A SUPPRIMER
int		ft_draw_grid(t_env *e);
void	ft_draw_img(t_env *e);
void	ft_create_win(t_env *e);
#endif
