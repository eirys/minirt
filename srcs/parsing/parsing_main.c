/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:48:23 by sdummett          #+#    #+#             */
/*   Updated: 2022/06/04 15:48:42 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	process_lines(int fd, t_objs **objs)
{
	int		ret;
	char	*line;

	ret = 1;
	*objs = NULL;
	printf(GRN"Parsing the description file ongoing...\n"RESET);
	while (ret != 0)
	{
		ret = get_next_line(fd, &line);
		if (ret == -1)
		{
			get_next_line(-1, NULL);
			printf(RED"Error: Reading file has failed.\n"RESET);
			return (0);
		}
		if (!parsing_line(line, objs))
		{
			get_next_line(-1, NULL);
			clear_objs(objs, free);
			free(line);
			return (0);
		}
		free(line);
	}
	return (1);
}

int	parse_file(t_scene *sc, int fd)
{
	t_objs	*objs;

	if (!process_lines(fd, &objs))
		return (0);
	if (!check_duplicates(objs) || !store_objects(sc, objs))
	{
		clear_objs(&objs, free);
		return (0);
	}
	clear_objs(&objs, free);
	printf(GRN"Parsing the description file has been done successfully.\n"RESET);
	return (1);
}
