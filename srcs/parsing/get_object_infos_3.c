/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_get_object_infos_3.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 13:18:05 by sdummett          #+#    #+#             */
/*   Updated: 2022/06/03 13:18:21 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	get_pattern(char **line, int *pattern)
{
	if (**line == 'c')
		*pattern = CHECKERBOARD;
	else
		return ;
	(*line)++;
	skip_whitespaces(line);
}
