/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerboard.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:47:32 by etran             #+#    #+#             */
/*   Updated: 2022/06/11 16:30:59 by eli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	checkerboard_plane(t_vec pos, int c[3], t_plane p)
{
	t_vec		vec;
	t_vec		pattern;
	int			lit;
	int			tmp[3];

	vec = create_vec(p.o, pos);
	pattern.x = scalar(vec, p.v);
	pattern.y = scalar(vec, p.u);
	lit = (modulo1(pattern.x / SCALE_TEXTURE) < .5f)
		^ (modulo1(pattern.y / SCALE_TEXTURE) < .5f);
	if (!lit)
		return ;
	tmp[0] = -lit * 120;
	tmp[1] = -lit * 120;
	tmp[2] = -lit * 120;
	sec_add_color(c, tmp);
}

static void	checkerboard_sphere(t_vec normal, int c[3])
{
	t_vec		pattern;
	int			lit;
	int			tmp[3];

	pattern.x = (1 + atan2(normal.z, normal.x) / M_PI) * .5f;
	pattern.y = acosf(normal.y) / M_PI;
	lit = (fmod(pattern.x * SCALE_TEXTURE, 1) < .5f)
		^ (fmod(pattern.y * SCALE_TEXTURE, 1) < .5f);
	if (!lit)
		return ;
	tmp[0] = -lit * 90;
	tmp[1] = -lit * 90;
	tmp[2] = -lit * 90;
	sec_add_color(c, tmp);
}

static void	checkerboard_cyl(t_vec normal, int c[3], t_vec pos, t_plane p)
{
	t_vec		pattern;
	t_vec		vec;
	int			lit;
	int			tmp[3];

	vec = create_vec(p.o, pos);
	pattern.x = scalar(vec, p.vec);
	pattern.y = atanf(scalar(normal, p.u) / scalar(normal, p.v)) / M_PI;
	lit = (modulo1(pattern.x / SCALE_TEXTURE) < .5f)
		^ (modulo1(pattern.y * SCALE_TEXTURE) < .5f);
	if (!lit)
		return ;
	tmp[0] = -lit * 90;
	tmp[1] = -lit * 90;
	tmp[2] = -lit * 90;
	sec_add_color(c, tmp);
}

void	pattern(t_int *i, int color[3])
{
	if (i->pattern == CHECKERBOARD)
	{
		if (i->type == SP_ID)
			return (checkerboard_sphere(i->normal, color));
		else if (i->type == PL_ID)
			return (checkerboard_plane(i->hit, color, *((t_plane *)i->object)));
		else if (i->type == CY_ID)
			return (checkerboard_cyl(i->normal, color, i->hit,
					((t_cylinder *)i->object)->p[0]));
		else if (i->type == CO_ID)
			return (checkerboard_cyl(i->normal, color, i->hit,
					((t_cone *)i->object)->p));
	}
}
