/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 14:52:41 by sdummett          #+#    #+#             */
/*   Updated: 2022/06/04 15:20:09 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	free_win(t_window *win)
{
	if (win->win_ptr)
		mlx_destroy_window(win->mlx_ptr, win->win_ptr);
	if (win->pic.img)
		mlx_destroy_image(win->mlx_ptr, win->pic.img);
	if (win->mlx_ptr)
	{
		mlx_destroy_display(win->mlx_ptr);
		free(win->mlx_ptr);
	}
}

void	free_scene(t_scene *sc)
{
	free(sc->sp);
	free(sc->pl);
	free(sc->cy);
	free(sc->co);
	free(sc->l);
}

int	cleanup_exit(t_window *win)
{
	free_win(win);
	free_scene(&win->sc);
	exit(EXIT_SUCCESS);
	return (0);
}
