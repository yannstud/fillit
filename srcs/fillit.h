/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 01:54:15 by adauchy           #+#    #+#             */
/*   Updated: 2017/11/18 10:26:11 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

typedef struct		s_data
{
	unsigned short	*list;
	int				size_list;
	char			**map;
	char			**final_map;
	int				size_square;
	int				size_map;
}					t_data;

int					ft_putstr(char *str);
int					get_tetriminos_list(char *name, unsigned short **list,
										int *nb_pieces);
void				lefter(char str[600], int count);
void				topper(char str[600], int count);
int					verify_piece(unsigned short piece);
int					get_best_combination(t_data *data, int index);
int					get_size_square(char **map, int size_map);
void				remove_piece(int x, int y, int index, t_data *data);
void				print_map(char **map, int size_square);
int					check_place(int x, int y, int index, t_data *data);
void				write_piece(int x, int y, int index, t_data *data);
void				reset_map(char **map, int size_map);
void				copy_map(char **dest, char **src, int size);
int					init_map(char ***map);
void				put_in_list(char piece[600], int count, int pos,
								unsigned short *list);
int					check_error_tetriminos(char str[600], int count);

#endif
