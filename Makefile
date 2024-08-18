# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dopereir <dopereir@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/05 22:30:08 by dopereir          #+#    #+#              #
#    Updated: 2024/08/18 16:37:38 by dopereir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
TEST_EXEC = test_printf

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = $(wildcard *.c)
BONUS_SRCS = $(wildcard *_bonus.c)
TEST_SRCS = main_test.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
TEST_OBJS = $(TEST_SRCS:.c=.o)

AR = ar rc
RANLIB = ranlib

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $^
	$(RANLIB) $@

bonus: $(OBJS) $(BONUS_OBJS)
	$(AR) $(NAME) $^
	$(RANLIB) $(NAME)

test: $(TEST_EXEC)

$(TEST_EXEC): $(NAME) $(TEST_OBJS)
	$(CC) $(CFLAGS) -o $@ $(TEST_OBJS) -L. -lftprintf

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

valgrind: $(TEST_EXEC)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TEST_EXEC)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS) $(TEST_OBJS)

fclean: clean
	$(RM) $(NAME) $(TEST_EXEC)

re: fclean all

re_bonus: fclean bonus

.PHONY: all bonus valgrind clean fclean re test
