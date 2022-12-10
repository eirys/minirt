/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 15:22:59 by etran             #+#    #+#             */
/*   Updated: 2022/03/12 18:09:04 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	error_input(char *msg)
{
	ft_putstr_fd(msg, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	return (EXIT_FAILURE);
}

int	errorfatal(t_window *win)
{
	printf("[FATAL ERROR] : %s\n", strerror(errno));
	free_win(win);
	return (EXIT_FAILURE);
}
