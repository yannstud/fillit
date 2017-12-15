/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size_square.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 09:52:48 by adauchy           #+#    #+#             */
/*   Updated: 2017/11/18 10:26:00 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			get_lenght_square(char **map, int size_map)
{
	int		h;
	int		l;

	l = size_map - 1;
	while (l >= 0)
	{
		h = size_map - 1;
		while (h >= 0 && map[h][l] == '.')
			h -= 1;
		if (h >= 0)
			return (l + 1);
		l--;
	}
	return (l + 1);
}

int			get_height_square(char **map, int size_map)
{
	int		h;
	int		l;

	h = size_map - 1;
	while (h >= 0)
	{
		l = size_map - 1;
		while (l >= 0 && map[h][l] == '.')
			l -= 1;
		if (l >= 0)
			return (h + 1);
		h--;
	}
	return (h + 1);
}

int			get_size_square(char **map, int size_map)
{
	int		h;
	int		l;

	h = get_height_square(map, size_map);
	l = get_lenght_square(map, size_map);
	if (h > l)
		return (h);
	return (l);
}
