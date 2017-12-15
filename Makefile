# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysalaun <ysalaun@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/18 10:17:36 by adauchy           #+#    #+#              #
#    Updated: 2017/12/02 23:08:52 by ysalaun          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = 		gcc

CFLAGS = 	-Wextra -Wall -Werror

RM = 		rm -f

NAME = 		fillit

SRCS	=	srcs/main.c					\
			srcs/get_tetriminos_list.c 	\
			srcs/tools.c				\
			srcs/put_top_left.c			\
			srcs/recursive.c			\
			srcs/get_size_square.c		\
			srcs/piece_on_map.c			\
			srcs/map_actions.c			\

OBJS	=	$(SRCS:.c=.o)

all	:		$(NAME)

$(NAME)	:	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean	:
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re	:		fclean all

.PHONY	:	all clean fclean re
