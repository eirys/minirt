/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:42:09 by sdummett          #+#    #+#             */
/*   Updated: 2022/06/04 17:17:31 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	check_format_bonus(char **line, int id, int *ret)
{
	if (*ret && (id == SP_ID || id == PL_ID || id == CY_ID || id == CO_ID))
		*ret = check_coefficient_format(line);
	if (*ret && (id == SP_ID || id == PL_ID || id == CY_ID || id == CO_ID))
		*ret = check_texture_format(line);
}

static void	continue_check(char **line, int id, int *ret)
{
	if (*ret && id == C_ID)
		*ret = check_fov_format(line);
	if (*ret && id == L_ID)
		*ret = check_brightness_format(line);
	if (*ret && (id == SP_ID || id == CY_ID || (BONUS && id == CO_ID)))
		*ret = check_diameter_format(line);
	if (*ret && (id == CY_ID || (BONUS && id == CO_ID)))
		*ret = check_height_format(line);
	if (*ret && (id == A_ID || id == SP_ID || id == PL_ID || id == CY_ID
			|| (BONUS && (id == L_ID || id == CO_ID))))
		*ret = check_color_format(line);
}

int	check_format(char *line, int id)
{
	int	ret;

	ret = 1;
	skip_identifier(&line);
	if (ret && id == A_ID)
		ret = check_ambient_light_format(&line);
	if (ret && (id == C_ID || id == L_ID || id == SP_ID
			|| id == PL_ID || id == CY_ID || (BONUS && id == CO_ID)))
		ret = check_coordinates_format(&line);
	if (ret && (id == C_ID || id == PL_ID || id == CY_ID
			|| (BONUS && id == CO_ID)))
		ret = check_vec_format(&line);
	continue_check(&line, id, &ret);
	if (BONUS)
		check_format_bonus(&line, id, &ret);
	if (*line != '\0')
		ret = 0;
	return (ret);
}
