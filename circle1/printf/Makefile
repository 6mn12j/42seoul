# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/04 12:47:42 by minjupar          #+#    #+#              #
#    Updated: 2021/07/04 14:01:23 by minjupar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC_DIR = ./
NAME = libftprintf.a

SRCS = $(addprefix ${SRC_DIR},\
ft_printf.c\
ft_printf_num.c\
ft_printf_string.c\
ft_printf_utils1.c\
ft_printf_utils2.c\
ft_printf_utils3.c)

INCLUDE = ft_printf.h
OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

.PHONY: all
all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCLUDE) -c -o  $@ $<

$(NAME): $(OBJS)
	ar rc $@ $^

.PHONY: clean
clean:
	rm -f $(OBJS)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean all

