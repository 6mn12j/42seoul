SRC_DIR = ./
NAME = ft_printf.a

SRCS = $(addprefix ${SRC_DIR},\
ft_printf.c\
ft_printf_utils1.c\
ft_printf_utils2.c)


OBJS = $(SRCS:.c=.o)


CC = gcc
CFLAGS = -Wall -Wextra -Werror

.PHONY: all
all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

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

