/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 02:08:11 by adauchy           #+#    #+#             */
/*   Updated: 2017/11/18 10:18:53 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				test_combination(int h, int l, t_data *data, int index)
{
	int			size;

	write_piece(l, h, index, data);
	size = get_size_square(data->map, data->size_map);
	if (index < data->size_list - 1 && !get_best_combination(data, index + 1))
		return (0);
	if (index == data->size_list - 1 &&
		(size < data->size_square || !data->size_square))
	{
		data->size_square = size;
		reset_map(data->final_map, data->size_map);
		copy_map(data->final_map, data->map, data->size_square);
		data->size_map = size;
		if (data->size_list * 4 > (data->size_square - 1) *
				(data->size_square - 1))
			return (0);
	}
	remove_piece(l, h, index, data);
	return (1);
}

int				get_best_combination(t_data *data, int index)
{
	int	h;
	int	l;

	h = 0;
	while (h < data->size_map)
	{
		l = 0;
		while (l < data->size_map)
		{
			if (check_place(l, h, index, data) &&
					!test_combination(h, l, data, index))
				return (0);
			l++;
		}
		h++;
	}
	return (1);
}
