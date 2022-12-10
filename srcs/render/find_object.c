/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eli <etran@42.student.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 16:48:00 by eli               #+#    #+#             */
/*   Updated: 2022/06/03 16:52:50 by eli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/* For each object type, finds the closest to camera (screen) */
bool	find_object(t_window *win, t_ray ray, t_objs *objs, t_int *max)
{
	t_int		intersection[4];
	float		values[4];
	t_objs		tmp[4];
	int			index;

	fill_object_tab(win, ray, intersection, tmp);
	if (!tmp[0].content && !tmp[1].content && !tmp[2].content
		&& !tmp[3].content)
		return (false);
	values[0] = intersection[0].inter;
	values[1] = intersection[1].inter;
	values[2] = intersection[2].inter;
	values[3] = intersection[3].inter;
	index = min_arrf(values, 4);
	objs->content = tmp[index].content;
	objs->id = 4 + index;
	*max = intersection[index];
	return (true);
}
