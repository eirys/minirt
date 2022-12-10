/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 11:50:48 by sdummett          #+#    #+#             */
/*   Updated: 2022/03/18 17:18:08 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	skip_identifier(char **line)
{
	skip_whitespaces(line);
	if (ft_isalpha(**line))
		*line = *(line) + 2;
	else
		*line = *(line) + 1;
	skip_whitespaces(line);
}

t_objs	*new_objs(void *content, int id)
{
	t_objs	*new_el;

	new_el = ft_calloc(1, sizeof(t_objs));
	if (!new_el)
		return (NULL);
	new_el->next = NULL;
	new_el->id = id;
	new_el->content = content;
	return (new_el);
}

void	clear_objs(t_objs **lst, void (*del)(void *))
{
	t_objs	*temp;

	while (*lst)
	{
		temp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = temp;
	}
}

void	add_front_objs(t_objs **alst, t_objs *new)
{
	new->next = *alst;
	*alst = new;
}

int	push_object(t_objs **objs, void *content, int id)
{
	t_objs	*new;

	new = new_objs(content, id);
	if (!new)
	{
		free(content);
		return (0);
	}
	add_front_objs(objs, new);
	return (1);
}
