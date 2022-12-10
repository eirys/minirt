/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof_dectobin_exp.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:09:22 by sdummett          #+#    #+#             */
/*   Updated: 2022/03/18 16:13:33 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	dectobin_justifyleft(t_float *iflt)
{
	if (!iflt->frac_d.msb && !iflt->frac_d.lsb)
		return ;
	while (!((iflt->frac_d.msb) >> 60))
	{
		iflt->frac_d = uint128_leftshift(iflt->frac_d, 1);
		iflt->exp--;
	}
	iflt->frac_d = uint128_rightshift(iflt->frac_d, 1);
	iflt->exp++;
}

static void	dectobin_justifyright(t_float *iflt)
{
	while (iflt->frac_d.msb >> 60)
	{
		iflt->frac_d = uint128_rightshift(iflt->frac_d, 1);
		iflt->exp++;
	}
}

static void	dectobin_exppos(t_float *iflt)
{
	while (iflt->exp_d > 0)
	{
		iflt->frac_d = uint128_tenx(iflt->frac_d);
		dectobin_justifyright(iflt);
		iflt->exp_d--;
	}
}

static void	dectobin_expneg(t_float *iflt)
{
	while (iflt->exp_d < 0)
	{
		iflt->frac_d = uint128_tendiv(iflt->frac_d);
		dectobin_justifyleft(iflt);
		iflt->exp_d++;
	}
}

void	ft_atof_dectobin_exp(t_float *iflt)
{
	if (iflt->exp_d < (-324 - 18) || iflt->frac_d.lsb == 0)
	{
		iflt->exp = -1023;
		iflt->frac_d.lsb = 0;
	}
	else if (iflt->exp_d > 308 + 18)
	{
		iflt->exp = 1024;
		iflt->frac_d.lsb = 0;
	}
	else
	{
		dectobin_justifyleft(iflt);
		iflt->exp += 123;
		if (iflt->exp_d > 0)
			dectobin_exppos(iflt);
		else if (iflt->exp_d < 0)
			dectobin_expneg(iflt);
		iflt->frac_d = uint128_leftshift(iflt->frac_d, 4);
	}
}
