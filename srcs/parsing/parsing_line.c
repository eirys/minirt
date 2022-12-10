/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:49:15 by sdummett          #+#    #+#             */
/*   Updated: 2022/05/27 11:13:05 by eli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	parsing_line(char *line, t_objs **objs)
{
	static int	line_nb = 1;

	if (check_identifier(line) == BAD_ID)
	{
		printf(RED"Error: Wrong identifier at line %d\n"RESET, line_nb);
		return (0);
	}
	else if (check_identifier(line) == 0 && line_nb++)
		return (1);
	if (!check_format(line, get_identifier(line)))
	{
		printf(RED"Error: Bad format at line %d\n"RESET, line_nb);
		return (0);
	}
	if (!get_object(line, get_identifier(line), objs))
	{
		printf(RED"[FATAL ERROR] : %s\n"RESET, strerror(errno));
		return (0);
	}
	line_nb++;
	return (1);
}

int	check_identifier(char *line)
{
	if (get_identifier(line) == BAD_ID)
		return (BAD_ID);
	else if (get_identifier(line) == 0)
		return (0);
	return (1);
}

int	get_identifier(char *line)
{
	skip_whitespaces(&line);
	if (*line == '\0')
		return (0);
	else if (*line == 'A' && ft_isspace(*(line + 1)))
		return (A_ID);
	else if (*line == 'C' && ft_isspace(*(line + 1)))
		return (C_ID);
	else if (*line == 'L' && ft_isspace(*(line + 1)))
		return (L_ID);
	else if (*line == 's' && *(line + 1) == 'p' && ft_isspace(*(line + 2)))
		return (SP_ID);
	else if (*line == 'p' && *(line + 1) == 'l' && ft_isspace(*(line + 2)))
		return (PL_ID);
	else if (*line == 'c' && *(line + 1) == 'y' && ft_isspace(*(line + 2)))
		return (CY_ID);
	else if (*line == 'c' && *(line + 1) == 'o' && ft_isspace(*(line + 2)))
		return (CO_ID);
	return (BAD_ID);
}
