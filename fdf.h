/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 14:53:54 by gphilips          #+#    #+#             */
/*   Updated: 2017/02/07 15:58:42 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FDF_H
# define FDF_H

# include "libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>

# define ESC 53
# define TAB 48
# define ENT 36
# define PLUS 35
# define MIN 37
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define FRONT 3
# define BACK 11
# define RED 83
# define GREEN 84
# define BLUE 85

typedef struct	s_color
{
	int		r;
	int		g;
	int		b;
}				t_color;

typedef struct	s_map
{
	int			x;
	int			y;
	int			z;
}				t_map;

typedef struct	s_file
{
	t_map		**map;
	char		**split;
	int			nb_x;
	int			nb_y;
	int			space;
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
	int			win_x;
	int			win_y;
	int			margin_l;
	int			margin_t;
	int			proj;
	void		*img;
	char		*data;
	int			bpp;
	int			sizeline;
	int			endian;
	t_file		file;
	t_list		*lst;
	t_point		point;
	t_color		color;
}				t_env;

t_env	*ft_init_all(t_env *e);
int		ft_read_file(int fd, t_env *e);
t_map	**ft_create_int_tab(t_list *lst, t_env *e);
void	ft_draw_grid(t_env *e);
void	ft_create_win(t_env *e);
int		ft_expose_hook(t_env *e);

void	ft_change_proj(t_env *e);
void	ft_change_depth(int key, t_env *e);
void	ft_zoom(int key, t_env *e);
void	ft_move(int key, t_env *e);
void	ft_reinit(t_env *e);

void	ft_free_node(void *content, size_t size);
void	ft_free_map(t_map **map, t_env *e);
#endif
