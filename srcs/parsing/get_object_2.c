/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_get_object_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:48:14 by sdummett          #+#    #+#             */
/*   Updated: 2022/06/03 15:34:08 by eli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	generate_directional_vec(t_plane *p)
{
	t_vec	tmp;
	t_vec	normal;

	normal = p->vec;
	tmp = generate_vec(0, 0, 1);
	if (scalar(normal, tmp) == 1)
		tmp = generate_vec(0, 1, 0);
	p->u = crossprod(normal, tmp);
	normalize(&p->u);
	p->v = crossprod(p->u, normal);
	normalize(&p->v);
}

int	get_plane(char *line, t_objs **objs)
{
	t_plane		*plane;
	float		vec[3];
	float		coord[3];

	plane = ft_calloc(1, sizeof(t_plane));
	if (!plane)
		return (0);
	get_coordinates(&line, coord);
	get_vector(&line, vec);
	get_color(&line, plane->color);
	plane->vec = convert_vect(vec);
	generate_directional_vec(plane);
	plane->o = convert_vect(coord);
	if (BONUS)
	{
		get_coefficient(&line, &plane->coef);
		get_pattern(&line, &plane->pattern);
	}
	if (!push_object(objs, plane, PL_ID))
		return (0);
	return (1);
}

static void	cylinder_pt2(char *line, t_cylinder *cylinder)
{
	if (BONUS)
	{
		get_coefficient(&line, &cylinder->coef);
		get_pattern(&line, &cylinder->pattern);
	}
	cylinder->r2 = cylinder->radius * cylinder->radius;
	cylinder->p[0].o = cylinder->center;
	cylinder->p[0].vec = cylinder->vec;
	cylinder->p[0].pattern = cylinder->pattern;
	cylinder->p[1].o = cylinder->edge;
	cylinder->p[1].vec = cylinder->vec;
	cylinder->p[1].pattern = cylinder->pattern;
	generate_directional_vec(cylinder->p);
	generate_directional_vec(cylinder->p + 1);
}

int	get_cylinder(char *line, t_objs **objs)
{
	t_cylinder	*cylinder;
	float		height;
	float		diam;
	float		vec[3];
	float		bot[3];

	cylinder = ft_calloc(1, sizeof(t_cylinder));
	if (!cylinder)
		return (0);
	get_coordinates(&line, bot);
	get_vector(&line, vec);
	get_diameter(&line, &diam);
	cylinder->radius = diam / 2;
	get_height(&line, &height);
	get_color(&line, cylinder->color);
	cylinder->vec = convert_vect(vec);
	normalize(&cylinder->vec);
	cylinder->center = convert_vect(bot);
	cylinder->edge = create_vec_equation(cylinder->center, \
			scaledvec(height, cylinder->vec));
	cylinder_pt2(line, cylinder);
	if (!push_object(objs, cylinder, CY_ID))
		return (0);
	return (1);
}
