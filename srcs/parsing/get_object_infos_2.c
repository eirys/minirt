/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_get_object_infos_2.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:49:17 by sdummett          #+#    #+#             */
/*   Updated: 2022/06/03 15:34:49 by eli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	get_diameter(char **line, float *diameter)
{
	*diameter = ft_atof(*line);
	skip_float(line);
	skip_whitespaces(line);
}

void	get_height(char **line, float *height)
{
	*height = ft_atof(*line);
	skip_float(line);
	skip_whitespaces(line);
}

void	get_brightness(char **line, float *brightness)
{
	*brightness = ft_atof(*line);
	skip_float(line);
	skip_whitespaces(line);
}

void	get_coefficient(char **line, float *coefficient)
{
	*coefficient = ft_atof(*line);
	skip_float(line);
	skip_whitespaces(line);
}
