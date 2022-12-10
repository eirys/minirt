/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myhuong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 14:25:54 by myhuong           #+#    #+#             */
/*   Updated: 2021/05/20 13:27:26 by etran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	n_abs(int n)
{
	if (n < 0)
		n = -n;
	return (n);
}

static int	n_size(int n)
{
	int			size;
	int			way;

	size = 1;
	way = 1;
	if (n < 0)
	{
		size++;
		way = -1;
		size = -size;
	}
	while (n / 10)
	{
		size += way;
		n /= 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	int		size;
	int		i;
	char	*dest;

	size = n_size(n);
	dest = malloc(sizeof(char) * (n_abs(size) + 1));
	if (!(dest))
		return (NULL);
	i = n_abs(size);
	dest[i] = '\0';
	while (i--)
	{
		dest[i] = n_abs(n % 10) + '0';
		n /= 10;
	}
	if (size < 0)
		dest[0] = '-';
	return (dest);
}
