/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 17:08:50 by etran             #+#    #+#             */
/*   Updated: 2021/05/20 13:43:58 by etran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	put(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long int	n_temp;

	n_temp = n;
	if (n_temp < 0)
	{
		n_temp = -n_temp;
		put('-', fd);
	}
	if (n_temp > 9)
	{
		ft_putnbr_fd(n_temp / 10, fd);
		put(n_temp % 10 + '0', fd);
	}
	if (n_temp <= 9)
		put(n_temp + '0', fd);
}
