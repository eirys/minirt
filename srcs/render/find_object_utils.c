/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_object_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 09:43:20 by etran             #+#    #+#             */
/*   Updated: 2022/06/03 17:11:21 by eli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_sphere	*find_sphere(t_sphere *s_tab, int sp_nb, t_int *max, t_ray ray)
{
	t_sphere	*s;
	t_int		inter;
	int			i;

	s = 0;
	i = -1;
	inter.inter = INFINI;
	while (++i < sp_nb)
	{
		if (intersect_sphere(s_tab[i], ray, &inter))
		{
			if (inter.inter < max->inter)
			{
				*max = inter;
				s = s_tab + i;
				max->coef = s->coef;
				max->pattern = s->pattern;
				max->object = s;
			}
		}
	}
	return (s);
}

static t_cylinder	*find_cylinder(t_cylinder *c_tab, int nb, t_int *max,
		t_ray ray)
{
	t_cylinder	*c;
	t_int		inter;
	int			i;

	inter.inter = INFINI;
	i = -1;
	c = 0;
	while (++i < nb)
	{
		if (intersect_cyl(c_tab[i], ray, &inter))
		{
			if (inter.inter < max->inter)
			{
				*max = inter;
				c = c_tab + i;
				max->coef = c->coef;
				max->pattern = c->pattern;
				if (max->type == CY_ID)
					max->object = c->p;
				else
					max->object = c;
			}
		}
	}
	return (c);
}

static t_plane	*find_plane(t_plane *p_tab, int nb, t_int *max, t_ray ray)
{
	t_plane	*p;
	t_int	inter;
	int		i;

	p = 0;
	i = -1;
	inter.inter = INFINI;
	while (++i < nb)
	{
		if (intersect_plane(p_tab[i], ray, &inter))
		{
			if (inter.inter < max->inter)
			{
				*max = inter;
				p = p_tab + i;
				max->coef = p->coef;
				max->pattern = p->pattern;
				max->object = p;
			}
		}
	}
	return (p);
}

static t_cone	*find_cone(t_cone *c_tab, int nb, t_int *max, t_ray ray)
{
	t_cone		*c;
	t_int		inter;
	int			i;

	inter.inter = INFINI;
	i = -1;
	c = 0;
	while (++i < nb)
	{
		if (intersect_cone(c_tab[i], ray, &inter))
		{
			if (inter.inter < max->inter)
			{
				*max = inter;
				c = c_tab + i;
				max->coef = c->coef;
				max->pattern = c->pattern;
				if (max->type == CO_ID)
					max->object = &c->p;
				else
					max->object = c;
			}
		}
	}
	return (c);
}

/* This will fill the intersection tab for the find_object function */
void	fill_object_tab(t_window *win, t_ray ray, t_int intersection[4],
		t_objs tmp[4])
{
	intersection[0].inter = INFINI;
	intersection[1].inter = INFINI;
	intersection[2].inter = INFINI;
	intersection[3].inter = INFINI;
	tmp[0].content = find_sphere(win->sc.sp, win->sc.sp_nb, intersection, ray);
	tmp[1].content = find_plane(win->sc.pl, win->sc.pl_nb, \
			intersection + 1, ray);
	tmp[2].content = find_cylinder(win->sc.cy, win->sc.cy_nb, \
			intersection + 2, ray);
	tmp[3].content = find_cone(win->sc.co, win->sc.co_nb, \
			intersection + 3, ray);
}
