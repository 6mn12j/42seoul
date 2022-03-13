# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/04 12:47:42 by minjupar          #+#    #+#              #
#    Updated: 2022/03/14 04:00:07 by minjupar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude

NAME = push_swap
CHECKER = checker

PUSH_SWAP_SRCS = src/push_swap/main.c\

CHECKER_SRCS = src/push_swap/checker.c\

LIST_SRCS = src/doublylist/doublylist.c \
				src/doublylist/doublylist2.c \
				src/doublylist/command_list.c \

LIBFT_SRCS = src/libft/libft.c \
					src/libft/libft2.c \
					src/libft/ft_putstr.c \
					src/libft/ft_strchr.c \
					src/libft/ft_strncmp.c \

UTILS_SRCS = src/push_swap/utils/command.c \
					src/push_swap/utils/command2.c \
					src/push_swap/utils/command3.c \
					src/push_swap/utils/error.c \
					src/push_swap/utils/push_utils1.c \
					src/push_swap/utils/push_utils2.c \
					src/push_swap/optimization/optimization1.c \
					src/push_swap/optimization/optimization2.c \
					src/push_swap/optimization/optimization_command.c \
					src/push_swap/push_swap/a_to.c \
					src/push_swap/push_swap/b_to.c \
					src/push_swap/push_swap/b_to2.c \

GNL_SRCS = src/get_next_line/get_next_line.c\
				src/get_next_line/get_next_line_utils.c\

OBJ_PUSH_SWAP = $(PUSH_SWAP_SRCS:.c=.o)
OBJ_CHECEKR = $(CHECKER_SRCS:.c=.o)
OBJ_UTILS = $(UTILS_SRCS:.c=.o)
OBJ_LIBFT = $(LIBFT_SRCS:.c=.o)
OBJ_LIST = $(LIST_SRCS:.c=.o)
OBJ_GNL = $(GNL_SRCS:.c=.o)

.PHONY: all
all:  $(NAME) $(CHECKER)

$(NAME): $(OBJ_PUSH_SWAP) $(OBJ_UTILS) $(OBJ_LIBFT) $(OBJ_LIST)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ_PUSH_SWAP) $(OBJ_UTILS) $(OBJ_LIBFT) $(OBJ_LIST)

$(CHECKER):$(OBJ_CHECEKR) $(OBJ_UTILS) $(OBJ_LIBFT) $(OBJ_GNL) $(OBJ_LIST)
	$(CC) $(CFLAGS) -o $(CHECKER) $(OBJ_CHECEKR) $(OBJ_UTILS) $(OBJ_LIBFT) $(OBJ_GNL) $(OBJ_LIST)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf $(OBJ_PUSH_SWAP) $(OBJ_LIBFT) $(OBJ_UTILS) $(OBJ_LIST) $(OBJ_GNL) $(OBJ_CHECEKR)

.PHONY: fclean
fclean: clean
	rm -rf $(NAME) $(CHECKER)

.PHONY: re
re: fclean all
