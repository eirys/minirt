/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 23:17:52 by etran             #+#    #+#             */
/*   Updated: 2021/05/20 16:46:57 by etran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	d_size;

	i = 0;
	d_size = ft_strlen(dst);
	if (dstsize > d_size)
	{
		while (i < dstsize - d_size - 1 && src[i])
		{
			dst[d_size + i] = src[i];
			i++;
		}
		dst[d_size + i] = '\0';
		return ((ft_strlen((char *)src)) + d_size);
	}
	return (ft_strlen((char *)src) + dstsize);
}
