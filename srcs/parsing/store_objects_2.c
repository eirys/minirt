/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_store_objects_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:25:05 by sdummett          #+#    #+#             */
/*   Updated: 2022/06/02 19:52:13 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	store_plane(t_scene *sc, t_objs *objs)
{
	int	i;

	sc->pl = ft_calloc(count_object(objs, PL_ID) + 1, \
		sizeof(t_plane));
	if (!sc->pl)
	{
		printf(RED"[FATAL ERROR] : %s\n"RESET, strerror(errno));
		return (0);
	}
	sc->pl_nb = count_object(objs, PL_ID);
	i = 0;
	while (objs)
	{
		if (objs->id == PL_ID)
		{
			*(sc->pl + i) = *(t_plane *)objs->content;
			i++;
		}
		objs = objs->next;
	}
	return (1);
}

int	store_cylinder(t_scene *sc, t_objs *objs)
{
	int	i;

	sc->cy = ft_calloc(count_object(objs, CY_ID) + 1, \
		sizeof(t_cylinder));
	if (!sc->cy)
	{
		printf(RED"[FATAL ERROR] : %s\n"RESET, strerror(errno));
		return (0);
	}
	sc->cy_nb = count_object(objs, CY_ID);
	i = 0;
	while (objs)
	{
		if (objs->id == CY_ID)
		{
			sc->cy[i] = *(t_cylinder *)objs->content;
			i++;
		}
		objs = objs->next;
	}
	return (1);
}

int	store_cone(t_scene *sc, t_objs *objs)
{
	int	i;

	sc->co = ft_calloc(count_object(objs, CO_ID) + 1, \
		sizeof(t_cone));
	if (!sc->co)
	{
		printf(RED"[FATAL ERROR] : %s\n"RESET, strerror(errno));
		return (0);
	}
	sc->co_nb = count_object(objs, CO_ID);
	i = 0;
	while (objs)
	{
		if (objs->id == CO_ID)
		{
			*(sc->co + i) = *(t_cone *)objs->content;
			i++;
		}
		objs = objs->next;
	}
	return (1);
}
