/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_object_infos_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:37:17 by sdummett          #+#    #+#             */
/*   Updated: 2022/06/07 18:51:53 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	get_coordinates(char **line, float *coordinates)
{
	*(coordinates + X) = ft_atof(*line);
	skip_float(line);
	(*line)++;
	*(coordinates + Y) = ft_atof(*line);
	skip_float(line);
	(*line)++;
	*(coordinates + Z) = ft_atof(*line);
	skip_float(line);
	skip_whitespaces(line);
}

void	get_vector(char **line, float *vec)
{
	*(vec + X) = ft_atof(*line);
	skip_float(line);
	(*line)++;
	*(vec + Y) = ft_atof(*line);
	skip_float(line);
	(*line)++;
	*(vec + Z) = ft_atof(*line);
	skip_float(line);
	skip_whitespaces(line);
}

void	get_fov(char **line, int *fov)
{
	*fov = ft_atoi(*line);
	skip_int(line);
	skip_whitespaces(line);
}

void	get_color(char **line, int *color)
{
	*(color + R) = ft_atoi(*line);
	skip_int(line);
	(*line)++;
	*(color + G) = ft_atoi(*line);
	skip_int(line);
	(*line)++;
	*(color + B) = ft_atoi(*line);
	skip_int(line);
	skip_whitespaces(line);
}

void	get_amb_light(char **line, float *ambient_light)
{
	*ambient_light = ft_atof(*line);
	skip_float(line);
	skip_whitespaces(line);
}
