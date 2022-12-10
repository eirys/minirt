/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:51:19 by sdummett          #+#    #+#             */
/*   Updated: 2022/06/08 10:28:09 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	check_duplicates(t_objs *objs)
{
	int	count;

	count = 0;
	count = count + count_camera(objs);
	count = count + count_ambient_light(objs);
	if (count != 2)
		return (0);
	count = count + count_light(objs);
	if (count < 3)
		return (0);
	return (1);
}

int	count_camera(t_objs *objs)
{
	if (count_object(objs, C_ID) == 0)
	{
		printf(RED"Error: No camera found.\n"RESET);
		return (0);
	}
	if (count_object(objs, C_ID) > 1)
	{
		printf(RED"Error: More than 1 camera found.\n"RESET);
		return (0);
	}
	return (1);
}

int	count_light(t_objs *objs)
{
	if (count_object(objs, L_ID) == 0)
	{
		printf(RED"Error: No light found.\n"RESET);
		return (0);
	}
	if (BONUS)
		return (1);
	if (count_object(objs, L_ID) > 1)
	{
		printf(RED"Error: More than 1 light found.\n"RESET);
		return (0);
	}
	return (1);
}

int	count_ambient_light(t_objs *objs)
{
	if (count_object(objs, A_ID) == 0)
	{
		printf(RED"Error: No ambient light found.\n"RESET);
		return (0);
	}
	if (count_object(objs, A_ID) > 1)
	{
		printf(RED"Error: More than 1 ambient light found.\n"RESET);
		return (0);
	}
	return (1);
}

int	count_object(t_objs *objs, int id)
{
	int	count;

	count = 0;
	while (objs)
	{
		if (objs->id == id)
			count++;
		objs = objs->next;
	}
	return (count);
}
