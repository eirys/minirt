/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 15:49:56 by etran             #+#    #+#             */
/*   Updated: 2021/05/20 16:38:28 by etran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char		*dest_temp;
	const char	*src_temp;
	size_t		i;

	i = 0;
	dest_temp = dst;
	src_temp = src;
	while (n--)
	{
		if ((unsigned char)*src_temp == (unsigned char)c)
		{
			*dest_temp = *src_temp;
			return (dst + i + 1);
		}
		*dest_temp++ = *src_temp++;
		i++;
	}
	return (NULL);
}
