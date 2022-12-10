/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_ray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 11:37:21 by myhuong           #+#    #+#             */
/*   Updated: 2022/06/07 13:21:43 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/* adapts pix x and y components to screen and transformation matrix */
t_vec	compute_vec(t_window *win, int coord[2], t_matrix m)
{
	t_vec	tmp;

	tmp.x = ((2 * (coord[0] + 0.5f) / win->width) - 1.f) * win->angle \
		* win->ratio;
	tmp.y = (1.f - 2 * ((coord[1] + 0.5f) / win->height)) * win->angle;
	tmp.z = 1;
	transform(m, &tmp);
	return (tmp);
}

/* Self explainatory lol */
t_ray	compute_ray(t_vec origin, t_vec dir)
{
	t_ray	ray;

	ray.origin = origin;
	ray.dir = create_vec(origin, dir);
	normalize(&ray.dir);
	return (ray);
}

/* Main rendering function. It will compute every pixel into rays and raytrace
   the whole scene. */
void	trace(t_window *win)
{
	t_matrix	m;
	t_ray		ray;
	int			px[2];
	t_objs		o;
	t_int		intersection;

	m = generate_matrix(win->sc.c.o, win->sc.c.vec);
	px[1] = 0;
	while (px[1] < win->height)
	{
		px[0] = 0;
		while (px[0] < win->width)
		{
			ray = compute_ray(win->sc.c.o, compute_vec(win, px, m));
			intersection.inter = INFINI;
			if (find_object(win, ray, &o, &intersection))
				img_put_pix(win, px[0], px[1], \
						phong_model(ray, o, &intersection, win->sc));
			px[0]++;
		}
		px[1]++;
	}
}
