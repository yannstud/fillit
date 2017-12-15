/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_top_left.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 01:58:08 by adauchy           #+#    #+#             */
/*   Updated: 2017/11/18 10:20:18 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		gotoleft(char str[600], int count)
{
	int		n;

	n = 0;
	while (n != 3)
	{
		str[count + n] = str[count + 1 + n];
		str[count + 5 + n] = str[count + 6 + n];
		str[count + 10 + n] = str[count + 11 + n];
		str[count + 15 + n] = str[count + 16 + n];
		n++;
	}
	str[count + n] = '.';
	str[count + n + 5] = '.';
	str[count + n + 10] = '.';
	str[count + n + 15] = '.';
}

void		lefter(char str[600], int count)
{
	int		action;
	int		height;
	int		n;

	n = 0;
	action = 1;
	while (n++ < 3)
	{
		height = 0;
		while (height < 4)
		{
			if (str[count] == '#')
				action = 0;
			count += 5;
			height++;
		}
		if (action == 0)
			return ;
		count -= 20;
		gotoleft(str, count);
	}
}

void		gototop(char str[600], int count)
{
	int		n;

	n = 0;
	while (n != 15)
	{
		str[count + n] = str[count + n + 5];
		str[count + n + 1] = str[count + n + 6];
		str[count + n + 2] = str[count + n + 7];
		str[count + n + 3] = str[count + n + 8];
		n += 5;
	}
	while (str[count + n] != '\n')
		str[count + n++] = '.';
}

void		topper(char str[600], int count)
{
	int		action;
	int		lenght;
	int		n;

	n = 0;
	lenght = 0;
	action = 1;
	while (n++ < 3)
	{
		lenght = 0;
		while (lenght < 4)
		{
			if (str[count] == '#')
				action = 0;
			lenght++;
			count++;
		}
		if (action == 0)
			return ;
		count -= 4;
		gototop(str, count);
	}
}
