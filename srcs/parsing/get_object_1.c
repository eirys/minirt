/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_object_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:36:55 by sdummett          #+#    #+#             */
/*   Updated: 2022/06/08 16:41:16 by eli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	get_object(char *line, int id, t_objs **objs)
{
	int	ret;

	skip_identifier(&line);
	if (id == A_ID)
		ret = get_ambient_light(line, objs);
	if (id == C_ID)
		ret = get_camera(line, objs);
	if (id == L_ID)
		ret = get_light(line, objs);
	if (id == PL_ID)
		ret = get_plane(line, objs);
	if (id == SP_ID)
		ret = get_sphere(line, objs);
	if (id == CY_ID)
		ret = get_cylinder(line, objs);
	if (id == CO_ID)
		ret = get_cone(line, objs);
	return (ret);
}

int	get_camera(char *line, t_objs **objs)
{
	t_camera	*camera;
	float		coord[3];
	float		vec[3];

	camera = ft_calloc(1, sizeof(t_camera));
	if (!camera)
		return (0);
	get_coordinates(&line, coord);
	get_vector(&line, vec);
	get_fov(&line, &camera->fov);
	camera->o = convert_vect(coord);
	camera->vec = convert_vect(vec);
	normalize(&camera->vec);
	if (!push_object(objs, camera, C_ID))
		return (0);
	return (1);
}

int	get_light(char *line, t_objs **objs)
{
	t_light	*light;
	float	coord[3];

	light = ft_calloc(1, sizeof(t_light));
	if (!light)
		return (0);
	get_coordinates(&line, coord);
	get_brightness(&line, &light->brightness);
	if (BONUS)
		get_color(&line, light->color);
	else
	{
		light->color[0] = 255;
		light->color[1] = 235;
		light->color[2] = 205;
	}
	light->o = convert_vect(coord);
	if (!push_object(objs, light, L_ID))
		return (0);
	return (1);
}

int	get_ambient_light(char *line, t_objs **objs)
{
	t_ambient_light	*ambient_light;

	ambient_light = ft_calloc(1, sizeof(t_ambient_light));
	if (!ambient_light)
		return (0);
	get_amb_light(&line, &ambient_light->ambient_light);
	get_color(&line, ambient_light->color);
	if (!push_object(objs, ambient_light, A_ID))
		return (0);
	return (1);
}

int	get_sphere(char *line, t_objs **objs)
{
	t_sphere	*sphere;
	float		diam;
	float		coord[3];

	sphere = ft_calloc(1, sizeof(t_sphere));
	if (!sphere)
		return (0);
	get_coordinates(&line, coord);
	get_diameter(&line, &diam);
	get_color(&line, sphere->color);
	if (BONUS)
	{
		get_coefficient(&line, &sphere->coef);
		get_pattern(&line, &sphere->pattern);
	}
	sphere->radius = diam / 2;
	sphere->r2 = sphere->radius * sphere->radius;
	sphere->center = convert_vect(coord);
	if (!push_object(objs, sphere, SP_ID))
		return (0);
	return (1);
}
