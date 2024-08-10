# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dopereir <dopereir@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/05 22:30:08 by dopereir          #+#    #+#              #
#    Updated: 2024/08/06 00:11:21 by dopereir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

TEST_EXEC = test_printf

SOURCES = $(wildcard *.c)

CC = gcc

FLAGS = -Wall -Wextra -Werror

AR = ar rc

RANLIB = ranlib

remove = rm -f

TEST_SRCS = main_test.c

TEST_OBJS = $(TEST_SRCS:.c=.o)

objs = $(SOURCES:.c=.o)

all: $(NAME) $(TEST_EXEC)

$(NAME): $(objs)
	$(AR) $(NAME) $(objs)
	$(RANLIB) $(NAME)

$(TEST_EXEC): $(NAME) $(TEST_OBJS)
	$(CC) $(FLAGS) -o $(TEST_EXEC) $(TEST_OBJS) -L. -lftprintf
	
%.o: %.c
	$(CC) $(FLAGS) -c -o $@ $<
	
clean:
	$(remove) $(objs) $(TEST_OBJS) $(TEST_EXEC)

valgrind: $(TEST_EXEC)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TEST_EXEC)

fclean:	clean
	$(remove) $(NAME)

re: fclean all

.PHONY: all valgrind clean fclean re
