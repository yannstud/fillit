/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 02:36:32 by adauchy           #+#    #+#             */
/*   Updated: 2017/11/18 10:45:13 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				init_data(t_data *data)
{
	if (init_map(&data->map) == -1)
		return (-1);
	if (init_map(&data->final_map) == -1)
		return (-1);
	data->size_square = 0;
	data->size_map = 0;
	while (data->size_map * data->size_map < data->size_list * 4)
		data->size_map++;
	return (0);
}

int				main(int ac, char **av)
{
	t_data		data;

	if (ac != 2)
	{
		ft_putstr("usage: fillit [file]\n");
		return (-1);
	}
	if (get_tetriminos_list(av[1], &data.list, &data.size_list) == -1)
	{
		ft_putstr("error\n");
		return (-1);
	}
	if (init_data(&data) == -1)
		return (-1);
	while (!data.size_square)
	{
		get_best_combination(&data, 0);
		data.size_map++;
	}
	print_map(data.final_map, data.size_square);
	return (0);
}
