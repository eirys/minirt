/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 15:28:33 by etran             #+#    #+#             */
/*   Updated: 2022/06/11 16:26:03 by eli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static	void	set_window_size(t_window *win)
{
	mlx_get_screen_size(win->mlx_ptr, &win->width, &win->height);
	win->width *= 0.85;
	win->height *= 0.85;
}

static void	initialize_picture(t_window *win, int fd)
{
	if (!parse_file(&win->sc, fd))
	{
		close(fd);
		cleanup_exit(win);
	}
	close(fd);
	win->mlx_ptr = mlx_init();
	if (!win->mlx_ptr)
		exit(errorfatal(win));
	set_window_size(win);
	render(win);
	win->win_ptr = mlx_new_window(win->mlx_ptr, win->width, \
		win->height, "miniRT");
	if (!win->win_ptr)
		exit(errorfatal(win));
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->pic.img, 0, 0);
}

static int	open_file(char *s)
{
	int		fd;

	if (!ft_isending(s, ".rt"))
	{
		error_input("Error: Wrong file type");
		return (-1);
	}
	fd = open(s, O_RDONLY);
	if (fd < 0)
	{
		error_input("Error: No such file");
		return (-1);
	}
	return (fd);
}

static int	keyhold(int keysym, t_window *win)
{
	if (keysym == XK_Escape || keysym == XK_q)
		cleanup_exit(win);
	return (0);
}

int	main(int ac, char **av)
{
	t_window	win;
	int			fd;

	if (ac != 2)
		return (error_input("Error: Incorrect number of arguments"));
	fd = open_file(av[1]);
	if (fd < 0)
		return (1);
	ft_bzero(&win, sizeof(win));
	initialize_picture(&win, fd);
	mlx_hook(win.win_ptr, DestroyNotify, StructureNotifyMask,
		cleanup_exit, &win);
	mlx_key_hook(win.win_ptr, keyhold, &win);
	mlx_loop(win.mlx_ptr);
	return (0);
}
