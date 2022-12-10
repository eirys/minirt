/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myhuong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 09:57:10 by myhuong           #+#    #+#             */
/*   Updated: 2022/06/08 16:46:22 by eli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	generate_line(float arr[3], float a, float b, float c)
{
	arr[0] = a;
	arr[1] = b;
	arr[2] = c;
}

/* This will compute the transformation matrix, with origin and v as
   directional vector */
t_matrix	generate_matrix(t_vec origin, t_vec v)
{
	t_matrix	m;
	t_vec		tmp;

	generate_line(m.t, origin.x, origin.y, origin.z);
	generate_line(m.z, v.x, v.y, v.z);
	tmp = generate_vec(0, 1, 0);
	if (scalar(tmp, v) == 1)
		tmp = generate_vec(0, 0, -1);
	else if (scalar(tmp, v) == -1)
		tmp = generate_vec(0, 0, 1);
	tmp = crossprod(tmp, v);
	normalize(&tmp);
	generate_line(m.x, tmp.x, tmp.y, tmp.z);
	tmp = crossprod(v, tmp);
	normalize(&tmp);
	generate_line(m.y, tmp.x, tmp.y, tmp.z);
	return (m);
}

/* This will transform the point (or vector) p using the matrix m */
void	transform(t_matrix m, t_vec *p)
{
	t_vec	v;

	v.x = m.x[0] * p->x + m.x[1] * p->y + m.x[2] * p->z + m.t[0];
	v.y = m.y[0] * p->x + m.y[1] * p->y + m.y[2] * p->z + m.t[1];
	v.z = m.z[0] * p->x + m.z[1] * p->y + m.z[2] * p->z + m.t[2];
	p->x = v.x;
	p->y = v.y;
	p->z = v.z;
}
