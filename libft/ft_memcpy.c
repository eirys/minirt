/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 15:14:22 by etran             #+#    #+#             */
/*   Updated: 2021/05/20 16:39:53 by etran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dest_temp;
	const char	*src_temp;

	dest_temp = dst;
	src_temp = src;
	if (dest_temp == NULL && src_temp == NULL)
		return (NULL);
	while (n--)
		*dest_temp++ = *src_temp++;
	return (dst);
}
