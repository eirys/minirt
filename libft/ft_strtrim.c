/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 00:45:56 by etran             #+#    #+#             */
/*   Updated: 2021/05/20 13:58:47 by etran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_charset(char c, const char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *charset)
{
	char	*dest;
	int		dest_size;
	int		k;

	if (!(s1 && charset))
		return (NULL);
	while (is_charset(*s1, charset))
		s1++;
	dest_size = ft_strlen(s1);
	while (dest_size && is_charset(s1[dest_size - 1], charset))
		dest_size--;
	dest = (char *)malloc(sizeof(char) * (dest_size + 1));
	if (!(dest))
		return (NULL);
	k = 0;
	while (k < dest_size && *s1)
		dest[k++] = *s1++;
	dest[k] = '\0';
	return (dest);
}
