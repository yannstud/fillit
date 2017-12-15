/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tetriminos_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 10:18:07 by adauchy           #+#    #+#             */
/*   Updated: 2017/11/18 10:27:43 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "fillit.h"

int			get_list(char str[600], unsigned short **list,
					int size_list)
{
	int		pos;
	int		count;

	count = 0;
	pos = 0;
	if ((*list = (unsigned short*)malloc(size_list *
					sizeof(unsigned short))) == NULL)
		return (-1);
	while (pos < size_list)
	{
		put_in_list(str, count, pos, *list);
		if (verify_piece((*list)[pos]) == -1)
			return (-1);
		pos++;
		count += 21;
	}
	return (0);
}

int			get_file(char *name, char buffer[600])
{
	int		id_file;
	int		size_read;

	if ((id_file = open(name, O_RDONLY)) == -1)
		return (-1);
	if ((size_read = read(id_file, buffer, 599)) == -1)
		return (-1);
	buffer[size_read] = '\0';
	return (0);
}

int			parsing(char str[600])
{
	int		count;
	int		nb_pieces;

	count = 0;
	nb_pieces = 0;
	while (str[count] != '\0')
	{
		if (count != 0 && str[count] != '\n')
			return (-1);
		if (str[count] == '\n' && count != 0)
			count++;
		if (check_error_tetriminos(str, count) == -1)
			return (-1);
		lefter(str, count);
		topper(str, count);
		count += 20;
		nb_pieces++;
	}
	if (nb_pieces == 0 || nb_pieces > 26)
		return (-1);
	return (nb_pieces);
}

int			get_tetriminos_list(char *name, unsigned short **list,
								int *nb_pieces)
{
	char		file[600];

	if (get_file(name, file) == -1)
		return (-1);
	if ((*nb_pieces = parsing(file)) == -1)
		return (-1);
	if (get_list(file, list, *nb_pieces) == -1)
		return (-1);
	return (0);
}
