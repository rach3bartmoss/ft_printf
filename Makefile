# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dopereir <dopereir@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/05 22:30:08 by dopereir          #+#    #+#              #
#    Updated: 2024/07/15 21:00:50 by rache            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SOURCES = $(wildcard *.c)

CC = gcc

FLAGS = -Wall -Wextra -Werror

AR = ar rc

RANLIB = ranlib

remove = rm -f

objs = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(objs)
	$(AR) $(NAME) $(objs)
	$(RANLIB) $(NAME)
	
%.o: %.c
	$(CC) $(FLAGS) -c -o $@ $<
	
clean:
	$(remove) $(objs)

fclean:	clean
	$(remove) $(NAME)

re: fclean all

.PHONY: all clean fclean re
