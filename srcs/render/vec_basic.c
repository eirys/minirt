/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_basic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 10:27:37 by etran             #+#    #+#             */
/*   Updated: 2022/05/15 15:07:40 by etran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/* Convert tab to t_vec */
t_vec	convert_vect(float c[3])
{
	t_vec	tmp;

	tmp.x = c[0];
	tmp.y = c[1];
	tmp.z = c[2];
	return (tmp);
}

/* Creates vec from 3 floats */
t_vec	generate_vec(float a, float b, float c)
{
	t_vec	tmp;

	tmp.x = a;
	tmp.y = b;
	tmp.z = c;
	return (tmp);
}

/* Creating vector from 2 points : v = end - origin */
t_vec	create_vec(t_vec origin, t_vec end)
{
	t_vec	tmp;

	tmp.x = end.x - origin.x;
	tmp.y = end.y - origin.y;
	tmp.z = end.z - origin.z;
	return (tmp);
}

/* Creating point from straight line equation : v = origin + scaled_dir */
t_vec	create_vec_equation(t_vec origin, t_vec scaled_dir)
{
	t_vec	tmp;

	tmp.x = origin.x + scaled_dir.x;
	tmp.y = origin.y + scaled_dir.y;
	tmp.z = origin.z + scaled_dir.z;
	return (tmp);
}

/* Computes cross product of a and b : v = a x b */
t_vec	crossprod(t_vec a, t_vec b)
{
	t_vec	res;

	res.x = a.y * b.z - b.y * a.z;
	res.y = a.z * b.x - b.z * a.x;
	res.z = a.x * b.y - b.x * a.y;
	return (res);
}
