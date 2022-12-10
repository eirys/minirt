/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:47:02 by etran             #+#    #+#             */
/*   Updated: 2022/06/03 17:09:45 by eli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/* BONUS : Check for CONES intersection */

static bool	is_inside_co(t_cone c, t_ray ray)
{
	t_vec	tmp;
	float	h;

	tmp = create_vec(c.o, ray.origin);
	h = scalar(tmp, c.vec);
	if (h >= 0 && h <= c.height)
	{
		h = (h / c.height) * c.radius;
		tmp = create_vec(tmp, scaledvec(scalar(tmp, c.vec), c.vec));
		return (scalar(tmp, tmp) < h * h);
	}
	return (false);
}

static void	edit_root(t_cone c, t_ray ray, t_int *racine, bool *plane)
{
	t_vec	trial;
	float	scalars[2];
	t_int	t;

	trial = create_vec_equation(ray.origin, scaledvec(racine->inter, ray.dir));
	scalars[0] = scalar(c.vec, create_vec(c.o, trial));
	scalars[1] = scalar(c.vec, create_vec(c.edge, trial));
	check_plane(c.p, ray, &t, c.r2);
	if (scalars[0] > 0 && scalars[1] < 0)
	{
		racine->hit = trial;
		if (t.inter < 0 || t.inter >= racine->inter)
			return ;
		else
			*racine = t;
	}
	else if (t.inter > 0 && scalars[1] >= 0)
		*racine = t;
	else
	{
		racine->inter = -1;
		return ;
	}
	*plane = true;
}

static void	compute_normal(t_cone c, t_int *i)
{
	t_vec	op;
	t_vec	z;

	op = create_vec(c.o, i->hit);
	z = create_vec(scaledvec(scalar(op, c.vec), c.vec), op);
	normalize(&z);
	i->normal = create_vec(scaledvec(c.radius, c.vec), scaledvec(c.height,
				z));
	i->type = CO_ID;
}

static bool	positive_delta(t_cone c, t_ray ray, t_int *i, t_int racines[2])
{
	t_int	*best_t;
	bool	is_plane[2];
	int		index;

	is_plane[0] = false;
	is_plane[1] = false;
	if (racines[0].inter > 0)
		edit_root(c, ray, racines, is_plane);
	if (racines[1].inter > 0)
		edit_root(c, ray, racines + 1, is_plane + 1);
	best_t = minimal_t(racines, racines + 1);
	if (!best_t)
		return (false);
	if (best_t == racines)
		index = 0;
	else
		index = 1;
	*i = racines[index];
	if (!is_plane[index])
		compute_normal(c, i);
	return (true);
}

bool	intersect_cone(t_cone co, t_ray ray, t_int *i)
{
	t_int	racines[2];
	float	arg[3];
	float	tmp1;
	float	tmp2;
	t_vec	vp;

	if (is_inside_co(co, ray))
	{
		i->inter = 0;
		return (true);
	}
	vp = create_vec(co.o, ray.origin);
	tmp1 = scalar(co.vec, ray.dir);
	tmp2 = scalar(co.vec, vp);
	arg[0] = tmp1 * tmp1 - co.c_theta2;
	arg[1] = 2 * (tmp1 * tmp2 - co.c_theta2 * scalar(ray.dir, vp));
	arg[2] = tmp2 * tmp2 - co.c_theta2 * scalar(vp, vp);
	if (!discriminant(arg[0], arg[1], arg[2], racines))
		return (false);
	return (positive_delta(co, ray, i, racines));
}
