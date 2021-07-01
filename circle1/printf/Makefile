SRC_DIR = ./
NAME = libftprintf.a

SRCS = $(addprefix ${SRC_DIR},\
ft_printf.c\
ft_printf_num.c\
ft_printf_string.c\
ft_printf_utils1.c)

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

