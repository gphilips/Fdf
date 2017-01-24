/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 15:00:06 by gphilips          #+#    #+#             */
/*   Updated: 2017/01/24 17:07:34 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_error(int n)
{
	if (n == 1)
		ft_putendl("usage: ./fdf <filename> [ case_size z_size ]");
	if (n == 2)
		ft_putendl("error: something is wrong with the file");
	if (n == 3)
		ft_putendl("error: bad size of the file");
	return (-1);
}

int		main(int argc, char **argv)
{
	t_env	*e;
	int		fd;

	e = (t_env*)ft_memalloc(sizeof(t_env));
	if (argc != 2)
		return (ft_error(1) == -1 ? -1 : 0);
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		return (ft_error(2) == -1 ? -1 : 0);
	e = ft_init_all(e);
	if (ft_read_file(fd, e) == -1)
		return (ft_error(3) == -1 ? -1 : 0);
//	ft_draw_line(e);
	ft_create_win(e);
	if ((close(fd)) == -1)
		ft_error(2);
	return (0);
}
