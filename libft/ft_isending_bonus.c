/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isending_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 17:21:00 by etran             #+#    #+#             */
/*   Updated: 2022/02/28 17:30:51 by etran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* This function will extract the final characters of s and check if it 
   corresponds to the wanted string end */

int	ft_isending(char *s, char *end)
{
	size_t	len_s;
	size_t	len_end;

	if (!s || !end)
		return (0);
	len_s = ft_strlen(s);
	len_end = ft_strlen(end);
	if (len_s-- < len_end--)
		return (0);
	while (end[len_end] && s[len_s])
	{
		if (end[len_end--] != s[len_s--])
			return (0);
	}
	return (1);
}
