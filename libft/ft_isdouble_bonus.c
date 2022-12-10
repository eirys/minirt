/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdouble_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:37:51 by etran             #+#    #+#             */
/*   Updated: 2022/02/28 14:42:07 by etran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdouble(char *s)
{
	if (!s)
		return (0);
	if (!ft_isdigit(*s))
		return (0);
	while (*s && ft_isdigit(*s))
		s++;
	if (!*s)
		return (1);
	if (*s++ == '.')
	{
		while (*s && ft_isdigit(*s))
			s++;
		if (!*s)
			return (1);
	}
	return (0);
}
