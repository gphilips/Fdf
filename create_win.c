/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 15:46:19 by gphilips          #+#    #+#             */
/*   Updated: 2017/12/22 20:29:33 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Ca permet d'afficher les instructions dans la fenetre, au dessus de la map
static void	ft_instruction(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 10, 0, 0x00FFFFFF, CMD);
	mlx_string_put(e->mlx, e->win, 10, 20, 0x00FFFFFF, ISO);
	mlx_string_put(e->mlx, e->win, 10, 40, 0x00FFFFFF, ZOOM);
	mlx_string_put(e->mlx, e->win, 10, 60, 0x00FFFFFF, MOVE);
	mlx_string_put(e->mlx, e->win, 10, 80, 0x00FFFFFF, COLOR);
	mlx_string_put(e->mlx, e->win, 10, 100, 0x00FFFFFF, PROJ);
	mlx_string_put(e->mlx, e->win, 10, 120, 0x00FFFFFF, REINIT);
}

//Quand tu clic avec la souris, les espace entre les intersections s'elargi de 5
//Un clic droit fera le contraire
static int	ft_mouse_hook(int button, int x, int y, t_env *e)
{
	ft_putstr("Mouse ");
	ft_putnbr(button);
	ft_putstr(": x: ");
	ft_putnbr(x);
	ft_putstr(" | y: ");
	ft_putnbr(y);
	ft_putchar('\n');
	if (button == 1)
		e->file.space += 5;
	else if (button == 2 && e->file.space > 5)
		e->file.space -= 5;
	ft_expose_hook(e);
	return (0);
}

// Les keycodes representent des touches claviers qui emets des events.
// TAB permet de changer la variable e->proj vu tout a l'heure
// + et -la profondeur etc
static int	ft_key_hook(int keycode, t_env *e)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(e->mlx, e->win);
		free(e);
		exit(0);
	}
	else if (keycode == TAB)
		ft_change_proj(e);
	else if (keycode == PLUS || keycode == MIN)
		ft_change_depth(keycode, e);
	else if (keycode == FRONT || keycode == BACK)
		ft_zoom(keycode, e);
	else if (keycode == UP || keycode == DOWN
			|| keycode == LEFT || keycode == RIGHT)
		ft_move(keycode, e);
	else if (keycode == ENT)
		ft_reinit(e);
	else if (keycode == R || keycode == G || keycode == B)
		ft_change_color(keycode, e);
	ft_expose_hook(e);
	return (0);
}

//Je creer une image, je recreer un tableau d'int et je dessine la map
//Puis j'affiche l'image dans la fenetre
//Et j'affiche les instructions au dessus de la map
int			ft_expose_hook(t_env *e)
{
	e->img = mlx_new_image(e->mlx, e->win_x, e->win_y);
	e->data = mlx_get_data_addr(e->img, &e->bpp, &e->sizeline, &e->endian);
	ft_create_int_tab(e->lst, e);
	ft_draw_grid(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	ft_instruction(e);
	mlx_destroy_image(e->mlx, e->img);
	return (0);
}

//J'initialise la MLX, je cree une fenetre, je set l'event de la souris et du clavier
//Et je gere l'expose pour rafraichir l'image
int		ft_create_win(t_env *e)
{
	if (!(e->mlx = mlx_init()))
	{
		ft_putendl_fd("Error minilibx init", 2);
		return (-1);
	}
	e->win = mlx_new_window(e->mlx, e->win_x, e->win_y, "fdf");
	mlx_hook(e->win, KEYPRESS, KEYPRESSMASK, ft_key_hook, e);
	mlx_mouse_hook(e->win, ft_mouse_hook, e);
	mlx_expose_hook(e->win, ft_expose_hook, e);
	mlx_loop(e->mlx);
	return (0);
}
