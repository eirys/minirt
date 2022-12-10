/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_objects_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:48:23 by sdummett          #+#    #+#             */
/*   Updated: 2022/06/04 15:21:25 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	store_objects(t_scene *sc, t_objs *objs)
{
	int	(*f[7])();
	int	ret;
	int	i;

	f[0] = &store_camera;
	f[1] = &store_light;
	f[2] = &store_ambient_light;
	f[3] = &store_sphere;
	f[4] = &store_plane;
	f[5] = &store_cylinder;
	f[6] = &store_cone;
	ret = 1;
	i = 0;
	while (ret && i < 7)
		ret = f[i++](sc, objs);
	return (ret);
}

int	store_camera(t_scene *sc, t_objs *objs)
{
	while (objs && objs->id != C_ID)
		objs = objs->next;
	sc->c = *(t_camera *)objs->content;
	return (1);
}

int	store_light(t_scene *sc, t_objs *objs)
{
	int	i;

	sc->l = ft_calloc(count_object(objs, L_ID) + 1, \
		sizeof(t_light));
	if (!sc->l)
	{
		printf(RED"[FATAL ERROR] : %s\n"RESET, strerror(errno));
		return (0);
	}
	sc->l_nb = count_object(objs, L_ID);
	i = 0;
	while (objs)
	{
		if (objs->id == L_ID)
		{
			*(sc->l + i) = *(t_light *)objs->content;
			i++;
		}
		objs = objs->next;
	}
	return (1);
}

int	store_ambient_light(t_scene *sc, t_objs *objs)
{
	while (objs && objs->id != A_ID)
		objs = objs->next;
	sc->a = *(t_ambient_light *)objs->content;
	return (1);
}

int	store_sphere(t_scene *sc, t_objs *objs)
{
	int	i;

	sc->sp = ft_calloc(count_object(objs, SP_ID) + 1, \
		sizeof(t_sphere));
	if (!sc->sp)
	{
		printf(RED"[FATAL ERROR] : %s\n"RESET, strerror(errno));
		return (0);
	}
	sc->sp_nb = count_object(objs, SP_ID);
	i = 0;
	while (objs)
	{
		if (objs->id == SP_ID)
		{
			*(sc->sp + i) = *(t_sphere *)objs->content;
			i++;
		}
		objs = objs->next;
	}
	return (1);
}
