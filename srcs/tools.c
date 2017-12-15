/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 02:07:38 by adauchy           #+#    #+#             */
/*   Updated: 2017/11/18 10:32:38 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "fillit.h"

void		put_in_list(char piece[600], int count,
						int pos, unsigned short *list)
{
	int		n;

	n = 0;
	list[pos] = 0;
	while (n <= 18)
	{
		list[pos] = list[pos] << 1;
		if (piece[count + n] == '#')
			list[pos] = list[pos] | 1;
		if (n % 5 == 3)
			n += 2;
		else
			n++;
	}
}

int			ft_putstr(char *str)
{
	int		count;

	count = 0;
	while (str[count])
	{
		write(1, &str[count], 1);
		count++;
	}
	return (0);
}

int			verify_piece(unsigned short piece)
{
	int						count;
	static unsigned short	tetriminos[19] = {52224, 51328, 34952, 61440, 57856,
											17600, 36352, 27648, 35904, 50688,
											19584, 19968, 35968, 58368, 19520,
											35008, 11776, 50240, 59392};

	count = 0;
	while (count < 19)
	{
		if (piece == tetriminos[count])
			return (0);
		count++;
	}
	return (-1);
}

int			check_error_tetriminos(char str[600], int count)
{
	int		height;
	int		lenght;

	height = 0;
	while (height < 4)
	{
		lenght = 0;
		while (str[count] != '\n' && str[count] != '\0')
		{
			if (str[count] != '.' && str[count] != '#')
				return (-1);
			lenght++;
			count++;
		}
		if (str[count] != '\n' || lenght != 4)
			return (-1);
		count++;
		height++;
	}
	return (0);
}
