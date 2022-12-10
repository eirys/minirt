/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_model.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 10:07:41 by etran             #+#    #+#             */
/*   Updated: 2022/06/11 16:52:30 by eli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/* Complete Phong rendering model :
   C = b * (Cd + Cs) + Ca
   - C is the color of the pixel;
   - b is a boolean, returns true if the object intersected by the ray is in
   the shade;
   - Cd is the diffuse component of the color;
   - Cs is the specular component of the color (bonus);
   - Ca is the ambient component of the color;
 */

/* This will check whether or not the ray [hit point -> light] is obstructed
   by an object */
static bool	is_shadow(t_scene sc, t_ray light, t_int max, t_objs o)
{
	t_int	inter;

	inter = max;
	while (sc.pl_nb--)
		if (intersect_plane(sc.pl[sc.pl_nb], light, &inter) && sc.pl + \
			sc.pl_nb != o.content)
			if (inter.inter < max.inter)
				return (true);
	while (sc.sp_nb--)
		if (intersect_sphere(sc.sp[sc.sp_nb], light, &inter) && sc.sp + \
			sc.sp_nb != o.content)
			if (inter.inter < max.inter)
				return (true);
	while (sc.cy_nb--)
		if (intersect_cyl(sc.cy[sc.cy_nb], light, &inter) && sc.cy + \
			sc.cy_nb != o.content)
			if (inter.inter < max.inter)
				return (true);
	while (sc.co_nb--)
		if (intersect_cone(sc.co[sc.co_nb], light, &inter) && sc.co + \
			sc.co_nb != o.content)
			if (inter.inter < max.inter)
				return (true);
	return (false);
}

/* Compute ray [hit point -> light source] */
static t_ray	compute_light_ray(t_light l, t_int i, t_int *tmp)
{
	t_ray			light;

	light.origin = i.hit;
	light.dir = create_vec(light.origin, l.o);
	tmp->inter = get_norm(light.dir);
	normalize(&light.dir);
	return (light);
}

/* Compute ambient lit object's color */
/* + BONUS : This is where the pattern is added */
static bool	ambient_computing(t_ray ray, int c[3], t_int *i, t_scene sc)
{
	if (scalar(ray.dir, i->normal) > 0)
		i->normal = scaledvec(-1, i->normal);
	normalize(&i->normal);
	if (BONUS && i->pattern)
		pattern(i, c);
	ft_memcpy((void *)i->color, (const void *)c, 3 * sizeof(int));
	scaled_addition(i->color, sc.a.color, sc.a.ambient_light * .5f);
	if (i->inter == 0)
		return (false);
	return (true);
}

/* Computes diffuse light component */
/* + BONUS : Multiple coloured spot AND specular light component */
static float	illumination(t_ray light, t_ray ray, t_int i)
{
	t_vec	w;
	float	kd;
	float	ks;

	kd = scalar(i.normal, light.dir);
	if (BONUS && i.coef > 0 && kd > 0)
	{
		w = create_vec(light.dir, scaledvec(2 * scalar(light.dir, i.normal), \
				i.normal));
		normalize(&w);
		ks = scalar(w, scaledvec(-1, ray.dir));
		if (ks > 0)
			return (kd + powf(ks, i.coef));
	}
	return ((kd > 0) * kd);
}

/* Computes the color of the pixel following the Phong model as explained
   above */
int	phong_model(t_ray ray, t_objs o, t_int *i, t_scene sc)
{
	t_ray	light;
	t_int	tmp;
	float	coef;
	int		tmpc[3];
	int		c[3];

	color_cpy(c, o);
	if (!ambient_computing(ray, c, i, sc))
		return (convert_color(i->color));
	while (sc.l_nb--)
	{
		light = compute_light_ray(sc.l[sc.l_nb], *i, &tmp);
		if (!is_shadow(sc, light, tmp, o))
		{
			ft_memcpy((void *)tmpc, (const void *)c, 3 * sizeof(int));
			coef = sc.l[sc.l_nb].brightness
				* illumination(light, ray, *i);
			scaled_addition(tmpc, sc.l[sc.l_nb].color, coef * .5f);
			sec_add_color(i->color, tmpc);
		}
	}
	return (convert_color(i->color));
}
