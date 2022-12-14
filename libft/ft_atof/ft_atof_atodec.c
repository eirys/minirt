/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof_atodec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:09:11 by sdummett          #+#    #+#             */
/*   Updated: 2022/06/04 15:40:54 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	atodec_atoi(const char *str)
{
	int				sign;
	unsigned long	abs;

	sign = 1;
	abs = 0;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
		abs = abs * 10 + *(str++) - '0';
	return ((int)(sign * abs));
}

static const char	*atodec_findhead(const char *s, t_float *iflt)
{
	while (ft_isspace(*s))
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s++ == '-')
			iflt->sign = 1;
		else
			iflt->sign = 0;
	}
	while (*s == '0')
		s++;
	return (s);
}

static const char	*atodec_store_int(const char *s, t_float *iflt, int *digit)
{
	while (ft_isdigit(*s))
	{
		if (++(*digit) <= 18)
			iflt->frac_d.lsb = iflt->frac_d.lsb * 10 + *s - '0';
		else
			iflt->exp_d++;
		s++;
	}
	return (s);
}

static const char	*atodec_store(const char *s, t_float *iflt)
{
	int		digit;

	digit = 0;
	s = atodec_store_int(s, iflt, &digit);
	if (*s != 'e' && *s != 'E' && *s != '.')
		return (s);
	if (*s == '.')
		s++;
	while (ft_isdigit(*s))
	{
		if (++digit <= 18)
			iflt->frac_d.lsb = iflt->frac_d.lsb * 10 + *s - '0';
		if (digit <= 18)
			iflt->exp_d--;
		s++;
	}
	return (s);
}

void	ft_atof_atodec(const char *s, t_float *iflt)
{
	s = atodec_findhead(s, iflt);
	s = atodec_store(s, iflt);
	if (*s == 'e' || *s == 'E')
		iflt->exp_d += atodec_atoi(++s);
}
