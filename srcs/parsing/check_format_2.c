/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:43:09 by sdummett          #+#    #+#             */
/*   Updated: 2022/06/04 17:17:06 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	check_coordinates_format(char **line)
{
	int	i;

	if (**line == '\0')
		return (0);
	i = 0;
	while (i < 3)
	{
		if (!ft_isfloat(line) && **line != ',')
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

int	check_vec_format(char **line)
{
	int		i;
	int		is_null;
	float	vec_coor;

	if (**line == '\0')
		return (0);
	i = 0;
	is_null = 1;
	while (i < 3)
	{
		vec_coor = ft_atof(*line);
		if (vec_coor < -1.0f || vec_coor > 1.0f)
			return (0);
		if (vec_coor == 0 && is_null++ && is_null == 4)
			return (0);
		if (!ft_isfloat(line) && **line != ',')
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

int	check_fov_format(char **line)
{
	int	fov;

	if (**line == '\0')
		return (0);
	fov = ft_atoi(*line);
	if (fov < 0 || fov > 180)
		return (0);
	if (!ft_isint(line))
		return (0);
	skip_whitespaces(line);
	return (1);
}

int	check_brightness_format(char **line)
{
	float	brightness;

	if (**line == '\0')
		return (0);
	brightness = ft_atof(*line);
	if (!ft_isfloat(line))
		return (0);
	if (brightness < 0.0f || brightness > 1.0f)
		return (0);
	skip_whitespaces(line);
	return (1);
}

int	check_coefficient_format(char **line)
{
	float	coefficient;

	if (**line == '\0')
		return (0);
	coefficient = ft_atof(*line);
	if (!ft_isfloat(line))
		return (0);
	if (coefficient < 0.0f)
		return (0);
	skip_whitespaces(line);
	return (1);
}
