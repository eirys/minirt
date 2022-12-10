/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myhuong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 13:04:56 by myhuong           #+#    #+#             */
/*   Updated: 2021/05/20 13:44:58 by etran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*w_create(const char *s, char c)
{
	int		i;
	char	*dest_w;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	dest_w = malloc(sizeof(char) * (i + 1));
	if (!(dest_w))
		return (NULL);
	i = 0;
	while (*s && *s != c)
		dest_w[i++] = *s++;
	dest_w[i] = '\0';
	return (dest_w);
}

static int	w_count(const char *s, char c)
{
	int	nb_word;

	nb_word = 0;
	if (!(c) && *s)
		nb_word++;
	while (*s && c)
	{
		while (*s == c)
			s++;
		if (*s)
			nb_word++;
		while (*s && *s != c)
			s++;
	}
	return (nb_word);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	int		nb_word;
	int		i;
	int		k;

	if (!s)
		return (NULL);
	i = -1;
	nb_word = w_count(s, c);
	dest = malloc(sizeof(char *) * (nb_word + 1));
	if (!(dest))
		return (NULL);
	while (++i < nb_word)
	{
		k = 0;
		while (c && *s == c)
			s++;
		dest[i] = w_create(s, c);
		if (!dest[i])
			return (NULL);
		while (*s == dest[i][k++] && *s)
			s++;
	}
	dest[i] = 0;
	return (dest);
}
