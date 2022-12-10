/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 00:10:41 by etran             #+#    #+#             */
/*   Updated: 2021/05/20 16:51:06 by etran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	k;

	i = 0;
	if (!(needle[i]))
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		k = 0;
		while (haystack[i + k] == needle[k] && needle[k]
			&& (k + i) < len)
		{
			k++;
			if (!(needle[k]))
				return ((char *)haystack + i);
		}
		i++;
	}
	return (NULL);
}
