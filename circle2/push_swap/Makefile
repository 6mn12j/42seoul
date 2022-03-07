# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/04 12:47:42 by minjupar          #+#    #+#              #
#    Updated: 2022/03/07 01:42:38 by minjupar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude
NAME = push_swap

PUSH_SWAP_SRCS = src/push_swap/main.c \
					src/push_swap/utils/command.c \
					src/push_swap/utils/command2.c \
					src/push_swap/utils/command3.c \
					src/push_swap/utils/error.c \
					src/push_swap/utils/push_utils.c \
					src/push_swap/utils/push_utils2.c \
					src/push_swap/doublylist/doublylist.c \
					src/push_swap/doublylist/doublylist2.c \
					src/push_swap/optimization/optimization1.c \

LIBFT_SRCS = src/libft/ft_strtrim.c \
					src/libft/libft.c \


OBJ_PUSH_SWAP = $(PUSH_SWAP_SRCS:.c=.o)
OBJ_LIBFT = $(LIBFT_SRCS:.c=.o)

.PHONY: all
all:  $(NAME)

$(NAME): $(OBJ_PUSH_SWAP) $(OBJ_LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ_PUSH_SWAP) $(OBJ_LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf $(OBJ_PUSH_SWAP)  $(OBJ_LIBFT)

.PHONY: fclean
fclean: clean
	rm -rf $(NAME) $(OBJ_LIBFT)

.PHONY: re
re: fclean all
