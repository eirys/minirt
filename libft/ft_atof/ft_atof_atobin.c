/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof_atobin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:09:01 by sdummett          #+#    #+#             */
/*   Updated: 2022/03/18 16:10:43 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	init_ifloat(t_float *iflt)
{
	iflt->sign = 0;
	iflt->exp = 0;
	iflt->frac = 0;
	iflt->exp_d = 0;
	uint128_bzero(&(iflt->frac_d));
}

void	ft_atof_atobin(const char *s, t_float *iflt)
{
	init_ifloat(iflt);
	ft_atof_atodec(s, iflt);
	ft_atof_dectobin_exp(iflt);
	ft_atof_dectobin_frac(iflt);
}
