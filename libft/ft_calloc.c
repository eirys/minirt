/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myhuong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 11:44:33 by myhuong           #+#    #+#             */
/*   Updated: 2021/05/20 16:43:46 by etran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*dest;
	void	*dest_temp;
	size_t	total_size;

	total_size = count * size;
	dest = malloc(total_size);
	dest_temp = dest;
	if (!dest_temp)
		return (NULL);
	while (total_size--)
		*(char *)dest_temp++ = 0;
	return (dest);
}
