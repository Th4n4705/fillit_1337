# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: masali <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/14 12:21:18 by masali            #+#    #+#              #
#    Updated: 2018/10/17 16:11:25 by masali           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra  -Werror

all: $(NAME)

$(NAME):
	$(CC)  -c *.c -I.
	ar rc libft.a *.o
clean:
	rm -rf *.o
fclean: clean
	rm -rf *.a
re: fclean all
