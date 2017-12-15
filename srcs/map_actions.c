/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 10:18:25 by adauchy           #+#    #+#             */
/*   Updated: 2017/11/18 10:28:59 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "fillit.h"

int				init_map(char ***map)
{
	int			n;
	int			i;

	if ((*map = (char**)malloc(24 * sizeof(char*))) == NULL)
		return (-1);
	n = 0;
	while (n < 24)
	{
		if (((*map)[n] = (char*)malloc(24)) == NULL)
			return (-1);
		i = 0;
		while (i < 24)
			(*map)[n][i++] = '.';
		n++;
	}
	return (0);
}

void			print_map(char **map, int size_square)
{
	int		h;

	h = 0;
	while (h < size_square)
	{
		write(1, map[h++], size_square);
		write(1, "\n", 1);
	}
}

void			reset_map(char **map, int size_map)
{
	int	h;
	int	l;

	h = 0;
	while (h < size_map)
	{
		l = 0;
		while (l < size_map)
		{
			map[h][l] = '.';
			l++;
		}
		h++;
	}
}

void			copy_map(char **dest, char **src, int size_square)
{
	int	h;
	int	l;

	h = 0;
	while (h < size_square)
	{
		l = 0;
		while (l < size_square)
		{
			dest[h][l] = src[h][l];
			l++;
		}
		h++;
	}
}
