/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myhuong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 11:43:18 by myhuong           #+#    #+#             */
/*   Updated: 2022/05/27 16:22:36 by eli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/* Returns modulo 1 of number a, makes sure not negative */
float	modulo1(float a)
{
	a = a - floor(a);
	if (a < 0)
		a += 1;
	return (a);
}

/* Converts color tab to a hex (int) value */
unsigned int	convert_color(int c[3])
{
	return (c[0] << 16 | c[1] << 8 | c[2]);
}

/* Returns index of min in array of float */
int	min_arrf(float *arr, int size)
{
	int		index;
	int		i;

	if (size <= 1)
		return (0);
	i = 1;
	index = 0;
	while (i < size)
	{
		if (arr[index] > arr[i])
			index = i;
		i++;
	}
	return (index);
}

/* Computes quadratic formula with given variables and if any, returns
   the roots of the quadratic equation */
bool	discriminant(float a, float b, float c, t_int racines[2])
{
	float	delta;

	delta = b * b - (4 * c * a);
	if (delta >= 0)
	{
		delta = sqrt(delta);
		racines[0].inter = -(b - delta) / (2 * a);
		racines[1].inter = -(b + delta) / (2 * a);
	}
	else
		return (false);
	return (true);
}

/* This will return the best_t, smallest positive of the 2 t_int */
t_int	*minimal_t(t_int *inter1, t_int *inter2)
{
	float	t1;
	float	t2;

	t1 = inter1->inter;
	t2 = inter2->inter;
	if (t1 > 0)
	{
		if (t2 > 0 && t2 < t1)
			return (inter2);
		return (inter1);
	}
	else if (t2 > 0)
		return (inter2);
	return (0);
}
