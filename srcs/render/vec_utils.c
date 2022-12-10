/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 10:35:54 by etran             #+#    #+#             */
/*   Updated: 2022/06/08 16:49:42 by eli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/* Dot product of u and v */
float	scalar(t_vec u, t_vec v)
{
	return ((u.x * v.x) + (u.y * v.y) + (u.z * v.z));
}

/* Function f : f(v) = (1 / ||v||) * v */
void	normalize(t_vec *v)
{
	float	norm2;
	float	inv;

	norm2 = scalar(*v, *v);
	if (norm2 > 0)
	{
		inv = 1 / sqrt(norm2);
		v->x *= inv;
		v->y *= inv;
		v->z *= inv;
	}
}

/* Function f : f(v) = scal * v */
t_vec	scaledvec(float scal, t_vec v)
{
	t_vec	tmp;

	tmp = v;
	tmp.x *= scal;
	tmp.y *= scal;
	tmp.z *= scal;
	return (tmp);
}

/* Function f : f(v) = ||v|| */
float	get_norm(t_vec v)
{
	return (sqrt(scalar(v, v)));
}
