/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof_bintof.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:09:16 by sdummett          #+#    #+#             */
/*   Updated: 2022/03/18 16:12:34 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atof_bintof(t_float iflt)
{
	t_ufloat	ufloat;

	ufloat.mem = 0;
	ufloat.mem |= ((uint64_t)iflt.sign << 63);
	ufloat.mem |= ((uint64_t)iflt.exp << 52);
	ufloat.mem |= iflt.frac;
	return (ufloat.num);
}
