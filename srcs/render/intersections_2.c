/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 10:58:47 by etran             #+#    #+#             */
/*   Updated: 2022/06/03 17:29:12 by eli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/* Check for CYLINDERS intersection */

/* Computes specific intersection, if ray origin is inside the object then
   just consider the whole image as the object color. */
static bool	is_inside_cy(t_cylinder c, t_ray ray)
{
	t_vec	entire;
	t_vec	tmp;
	t_vec	tmp2;

	entire = create_vec(c.center, c.edge);
	tmp = create_vec(c.center, ray.origin);
	if (scalar(tmp, entire) >= 0
		&& scalar(create_vec(c.edge, ray.origin), entire) <= 0)
	{
		tmp2 = crossprod(tmp, entire);
		if (get_norm(tmp2) / get_norm(entire) <= c.radius)
			return (true);
	}
	return (false);
}

static bool	get_values_cyl(t_vec trial, float scalars[2], t_int *best_t,
		t_int *racine)
{
	if (scalars[0] > 0 && scalars[1] < 0)
	{
		racine->hit = trial;
		if (!best_t || (best_t->inter >= racine->inter))
			return (false);
		else
			*racine = *best_t;
	}
	else if ((scalars[0] <= 0 || scalars[1] >= 0) && best_t)
		*racine = *best_t;
	else
	{
		racine->inter = -1;
		return (false);
	}
	return (true);
}

/* Computes "better" roots for specific cases :
   - case 1: the root is good, it does indeed hit the round surface of the
   object, then do nothing (return regular value);
   - case 2: the hit point is considered on a round surface, but it's actually
   one of the cylinder's end. In that case, consider the end as a plane,
   if the hit point is beyond the cylinder's radius in said plane, consider it
   obsolete.
 */

static void	edit_root(t_cylinder c, t_ray ray, t_int *racine, bool *plane)
{
	t_vec	trial;
	float	scalars[2];
	t_int	t[2];
	t_int	*best_t;

	trial = create_vec_equation(ray.origin, scaledvec(racine->inter, ray.dir));
	scalars[0] = scalar(c.vec, create_vec(c.center, trial));
	scalars[1] = scalar(c.vec, create_vec(c.edge, trial));
	check_plane(c.p[0], ray, t, c.r2);
	check_plane(c.p[1], ray, t + 1, c.r2);
	best_t = minimal_t(t, t + 1);
	*plane = get_values_cyl(trial, scalars, best_t, racine);
}

/* In case of positive deltas, will check specific cases (cf. above) and
   compute normals and hit point accordingly.
 */
static bool	positive_delta(t_cylinder c, t_ray ray, t_int *i, t_int racines[2])
{
	t_int	*best_t;
	t_vec	tmp;
	bool	is_plane[2];
	int		index;

	if (racines[0].inter > 0)
		edit_root(c, ray, racines, is_plane);
	if (racines[1].inter > 0)
		edit_root(c, ray, racines + 1, is_plane + 1);
	best_t = minimal_t(racines, racines + 1);
	if (!best_t)
		return (false);
	index = 1;
	if (best_t == racines)
		index = 0;
	*i = racines[index];
	if (!is_plane[index])
	{
		tmp = create_vec(c.center, i->hit);
		i->normal = create_vec(scaledvec(scalar(c.vec, tmp), c.vec), tmp);
		i->type = CY_ID;
	}
	return (true);
}

bool	intersect_cyl(t_cylinder cy, t_ray ray, t_int *i)
{
	t_int	racines[2];
	float	arg[3];
	t_vec	sqa;
	t_vec	ort;

	if (is_inside_cy(cy, ray))
	{
		i->inter = 0;
		return (true);
	}
	sqa = create_vec(scaledvec(scalar(ray.dir, cy.vec), cy.vec), ray.dir);
	ort = scaledvec(scalar(create_vec(cy.center, ray.origin), cy.vec), cy.vec);
	ort = create_vec(ort, create_vec(cy.center, ray.origin));
	arg[0] = scalar(sqa, sqa);
	arg[1] = 2 * scalar(sqa, ort);
	arg[2] = scalar(ort, ort) - cy.r2;
	if (!discriminant(arg[0], arg[1], arg[2], racines))
		return (false);
	return (positive_delta(cy, ray, i, racines));
}
