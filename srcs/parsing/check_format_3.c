/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 12:41:49 by sdummett          #+#    #+#             */
/*   Updated: 2022/06/07 11:56:42 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	check_color_format(char **line)
{
	int		i;
	int		color;

	if (**line == '\0')
		return (0);
	i = 0;
	while (i < 3)
	{
		color = ft_atoi(*line);
		if (color < 0 || color > 255)
			return (0);
		if (!ft_isint(line) && **line != ',')
			return (0);
		if (i != 2 && **line == ',')
			(*line)++;
		else if (i == 2 && **line == ',')
			return (0);
		i++;
	}
	skip_whitespaces(line);
	return (1);
}

int	check_ambient_light_format(char **line)
{
	float	ambient_light;

	if (**line == '\0')
		return (0);
	ambient_light = ft_atof(*line);
	if (!ft_isfloat(line))
		return (0);
	if (ambient_light < 0.0f || ambient_light > 1.0f)
		return (0);
	skip_whitespaces(line);
	return (1);
}

int	check_diameter_format(char **line)
{
	float	diameter;

	diameter = ft_atof(*line);
	if (**line == '\0')
		return (0);
	if (!ft_isfloat(line))
		return (0);
	if (diameter <= 0)
		return (0);
	skip_whitespaces(line);
	return (1);
}

int	check_height_format(char **line)
{
	float	height;

	height = ft_atof(*line);
	if (**line == '\0')
		return (0);
	if (!ft_isfloat(line))
		return (0);
	if (height <= 0)
		return (0);
	skip_whitespaces(line);
	return (1);
}

int	check_texture_format(char **line)
{
	if (!**line)
		return (1);
	if (**line && **line != 'c')
		return (0);
	(*line)++;
	if (**line)
		return (0);
	skip_whitespaces(line);
	return (1);
}
