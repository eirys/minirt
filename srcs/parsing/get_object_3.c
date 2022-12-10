/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_get_object_3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 12:45:03 by sdummett          #+#    #+#             */
/*   Updated: 2022/06/03 16:05:28 by eli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	cone_pt2(char *line, t_cone *cone)
{
	get_coefficient(&line, &cone->coef);
	get_pattern(&line, &cone->pattern);
	cone->r2 = cone->radius * cone->radius;
	cone->c_theta2 = (cone->height * cone->height)
		/ (cone->height * cone->height + cone->r2);
	cone->p.o = cone->edge;
	cone->p.vec = cone->vec;
	generate_directional_vec(&cone->p);
}

int	get_cone(char *line, t_objs **objs)
{
	t_cone	*cone;
	float	vec[3];
	float	coord[3];
	float	diam;

	cone = ft_calloc(1, sizeof(t_cone));
	if (!cone)
		return (0);
	get_coordinates(&line, coord);
	get_vector(&line, vec);
	get_diameter(&line, &diam);
	cone->radius = diam / 2;
	get_height(&line, &cone->height);
	get_color(&line, cone->color);
	cone->vec = convert_vect(vec);
	normalize(&cone->vec);
	cone->o = convert_vect(coord);
	cone->edge = create_vec_equation(cone->o, \
			scaledvec(cone->height, cone->vec));
	cone_pt2(line, cone);
	if (!push_object(objs, cone, CO_ID))
		return (0);
	return (1);
}
