/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 14:55:14 by sdummett          #+#    #+#             */
/*   Updated: 2022/06/07 13:19:16 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	img_put_pix(t_window *win, int x, int y, int color)
{
	char	*pixel;

	pixel = win->pic.addr + (y * win->pic.line_length + \
			x * (win->pic.bits_per_pixel / 8));
	*(int *)pixel = color;
}

void	render(t_window *win)
{
	printf(GRN"Rendering the scene ongoing...\n"RESET);
	win->pic.img = mlx_new_image(win->mlx_ptr, win->width, win->height);
	if (!win->pic.img)
		exit(errorfatal(win));
	win->pic.addr = mlx_get_data_addr(win->pic.img, \
			&win->pic.bits_per_pixel, &win->pic.line_length, \
			&win->pic.endian);
	if (!win->pic.addr)
		exit(errorfatal(win));
	win->angle = tan(M_PI * 0.5 * (float)(win->sc.c.fov) / 180);
	win->ratio = (float)win->width / (float)win->height;
	if (BONUS)
		trace_multithreaded(win);
	else
		trace(win);
	printf(GRN"Rendering the scene has been done successfully.\n"RESET);
}
