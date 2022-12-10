/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 10:32:03 by etran             #+#    #+#             */
/*   Updated: 2022/05/27 17:13:02 by eli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/* Eh.. */
void	color_cpy(int dst[3], t_objs o)
{
	int	*src;

	if (o.id == SP_ID)
		src = ((t_sphere *)o.content)->color;
	else if (o.id == PL_ID)
		src = ((t_plane *)o.content)->color;
	else if (o.id == CO_ID)
		src = ((t_cone *)o.content)->color;
	else
		src = ((t_cylinder *)o.content)->color;
	dst[0] = src[0];
	dst[1] = src[1];
	dst[2] = src[2];
}

/* Makes sure value don't exceed UCHAR_MAX */
static int	secure_add(int v)
{
	if (v < 0)
		return (0);
	else if (v > UCHAR_MAX)
		return (UCHAR_MAX);
	else
		return (v);
}

/* Secured addition of 2 colors, cf. above */
void	sec_add_color(int d[3], int b[3])
{
	d[0] = secure_add(d[0] + b[0]);
	d[1] = secure_add(d[1] + b[1]);
	d[2] = secure_add(d[2] + b[2]);
}

/* Adds 2 colors (values can go up to 2 * UCHAR_MAX)
   and scales the additon. The .5f factor must be included in scale */
void	scaled_addition(int a[3], int b[3], float scale)
{
	a[0] = scale * (a[0] + b[0]);
	a[1] = scale * (a[1] + b[1]);
	a[2] = scale * (a[2] + b[2]);
}
