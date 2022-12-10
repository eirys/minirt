/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:33:04 by sdummett          #+#    #+#             */
/*   Updated: 2022/03/18 17:18:31 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	skip_whitespaces(char **line)
{
	while (ft_isspace(**line))
		(*line)++;
}

void	skip_int(char **line)
{
	while (ft_isdigit(**line) || **line == '-' || **line == '+')
		(*line)++;
}

void	skip_float(char **line)
{
	while (ft_isdigit(**line) || **line == '.' || **line == '-' \
	|| **line == '+')
		(*line)++;
}

int	ft_isint(char **line)
{
	if (**line == '+' || **line == '-')
		(*line)++;
	while (**line && !ft_isspace(**line))
	{
		if (!ft_isdigit(**line))
			return (0);
		(*line)++;
	}
	return (1);
}

int	ft_isfloat(char **line)
{
	if (**line == '+' || **line == '-')
		(*line)++;
	while (**line && !ft_isspace(**line) && **line != '.')
	{
		if (!ft_isdigit(**line) && **line != '.')
			return (0);
		(*line)++;
	}
	if (**line == '.')
	{
		(*line)++;
		if (!ft_isdigit(**line))
			return (0);
		while (**line && !ft_isspace(**line))
		{
			if (!ft_isdigit(**line))
				return (0);
			(*line)++;
		}
	}
	return (1);
}
