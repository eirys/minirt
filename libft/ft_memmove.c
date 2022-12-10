/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 17:51:46 by etran             #+#    #+#             */
/*   Updated: 2021/05/20 16:40:27 by etran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	const char	*src_temp;
	char		*dst_temp;

	if (dst < src)
	{
		src_temp = src;
		dst_temp = dst;
		while (n--)
			*dst_temp++ = *src_temp++;
	}
	else if (dst > src)
	{
		src_temp = src + n - 1;
		dst_temp = dst + n - 1;
		while (n--)
			*dst_temp-- = *src_temp--;
	}
	return (dst);
}
