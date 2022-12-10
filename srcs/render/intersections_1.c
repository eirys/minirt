/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myhuong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 11:55:55 by myhuong           #+#    #+#             */
/*   Updated: 2022/05/28 12:15:52 by eli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/* Check for SPHERES and PLANES intersections (t_int), normals and hit points
 if any */

static bool	is_inside_sp(t_sphere s, t_ray ray, t_int *i)
{
	t_vec	tmp;

	tmp = create_vec(ray.origin, s.center);
	if (scalar(tmp, tmp) - s.radius * s.radius > 0)
		return (false);
	i->inter = 0;
	return (true);
}

bool	intersect_sphere(t_sphere s, t_ray ray, t_int *i)
{
	t_vec	m;
	float	k;
	float	l;
	float	w;

	if (is_inside_sp(s, ray, i))
		return (true);
	m = create_vec(ray.origin, s.center);
	k = scalar(m, ray.dir);
	if (k < 0)
		return (false);
	l = scalar(m, m) - k * k;
	if (l > s.r2)
		return (false);
	w = sqrt(s.r2 - l);
	l = k - w;
	if (l < 0)
		l = k + w;
	if (l < 0)
		return (false);
	i->inter = l;
	i->hit = create_vec_equation(ray.origin, scaledvec(l, ray.dir));
	i->normal = create_vec(s.center, i->hit);
	i->type = SP_ID;
	return (true);
}

bool	intersect_plane(t_plane p, t_ray ray, t_int *i)
{
	float	m;
	float	k;
	float	t;

	k = scalar(ray.dir, p.vec);
	if (k == 0)
		return (false);
	m = scalar(create_vec(ray.origin, p.o), p.vec);
	t = m / k;
	if (t < 0)
		return (false);
	i->inter = t;
	i->hit = create_vec_equation(ray.origin, scaledvec(t, ray.dir));
	i->normal = p.vec;
	i->type = PL_ID;
	return (true);
}

/* Specific to cylinder/cone : special values computing (if on plane,
 cf. "edit_root" description*/
bool	check_plane(t_plane p, t_ray ray, t_int *t, float r2)
{
	t_vec	trial;

	t->inter = INFINI;
	if (intersect_plane(p, ray, t))
	{
		trial = create_vec(t->hit, p.o);
		if (scalar(trial, trial) <= r2)
			return (true);
	}
	t->inter = -1;
	return (false);
}
