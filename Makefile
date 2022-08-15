# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: masali <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/25 12:50:44 by masali            #+#    #+#              #
#    Updated: 2019/05/20 15:21:05 by masali           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc
CFLAGS = -Wall -Wextra  -Werror
FILE = ./fillit_extra.c ./fillit_extra_2.c ./fillit_extra_3.c ./fillit_extra_4.c ./fillit_extra_5.c ./get_tetris_lines.c ./main.c ./validation_table.c ./validation_string.c
all: $(NAME)

$(NAME):
		make -C libft
		$(CC) $(CFLAGS) -g -c $(FILE)
		$(CC) -g -o fillit *.o libft/libft.a
clean:
		rm -rf *.o
		make -C libft clean
fclean: clean
		rm -rf fillit
		make -C libft fclean
re: fclean all
