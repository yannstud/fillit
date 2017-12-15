/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_on_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 10:18:38 by adauchy           #+#    #+#             */
/*   Updated: 2017/11/18 10:18:41 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		remove_piece(int x, int y, int index, t_data *data)
{
	int				h;
	int				l;
	unsigned short	bit;

	h = 0;
	while (h < 4)
	{
		l = 0;
		while (l < 4)
		{
			bit = (unsigned short)(data->list[index] << (4 * h + l)) >> 15;
			if (bit)
				data->map[y + h][x + l] = '.';
			l++;
		}
		h++;
	}
}

int			check_place(int x, int y, int index, t_data *data)
{
	int				h;
	int				l;
	unsigned short	bit;

	h = 0;
	while (h < 4)
	{
		l = 0;
		while (l < 4)
		{
			bit = (unsigned short)(data->list[index] << (4 * h + l)) >> 15;
			if (bit && (h + y >= data->size_map || l + x >= data->size_map ||
					data->map[h + y][l + x] != '.'))
				return (0);
			l += 1;
		}
		h += 1;
	}
	return (1);
}

void		write_piece(int x, int y, int index, t_data *data)
{
	int				h;
	int				l;
	unsigned short	bit;

	h = 0;
	while (h < 4)
	{
		l = 0;
		while (l < 4)
		{
			bit = (unsigned short)(data->list[index] << (4 * h + l)) >> 15;
			if (bit)
				data->map[y + h][x + l] = index + 'A';
			l++;
		}
		h++;
	}
}
