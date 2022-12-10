/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atold_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:31:38 by etran             #+#    #+#             */
/*   Updated: 2022/02/28 15:17:51 by etran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* This function will exclusively a string like : "0155.24", with no
   whitespaces or anything at the front */

static long double	leftovers(char *s)
{
	long double	value;
	long double	div;

	value = 0;
	div = 1;
	if (*s && *s == '.')
	{
		s++;
		while (*s && ft_isdigit(*s))
		{
			div *= 10;
			value = value + (*s++ - '0') / div;
		}
		return (value);
	}
	return (0);
}

long double	ft_atold(char *s)
{
	long double	value;

	value = 0;
	while (*s && ft_isdigit(*s))
		value = value * 10 + *s++ - '0';
	value += leftovers(s);
	return (value);
}
