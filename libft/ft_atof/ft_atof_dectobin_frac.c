/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof_dectobin_frac.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:09:29 by sdummett          #+#    #+#             */
/*   Updated: 2022/03/18 16:13:57 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	dectobin_frac_setunnorm(t_float *iflt)
{
	if ((!iflt->frac_d.msb && !iflt->frac_d.lsb) || iflt->exp < -1074)
	{
		iflt->frac = 0;
		iflt->exp = -1023;
		return ;
	}
	iflt->frac_d.msb >>= (-1023 - iflt->exp);
	iflt->frac = iflt->frac_d.msb >> 12;
}

static void	dectobin_frac_setnorm(t_float *iflt)
{
	iflt->frac_d.msb <<= 1;
	iflt->frac = iflt->frac_d.msb >> 12;
}

void	ft_atof_dectobin_frac(t_float *iflt)
{
	if (iflt->exp > 1023)
	{
		iflt->exp = 2047;
		iflt->frac = 0;
		return ;
	}
	else if (iflt->exp < -1022)
		dectobin_frac_setunnorm(iflt);
	else
		dectobin_frac_setnorm(iflt);
	iflt->exp += 1023;
}
