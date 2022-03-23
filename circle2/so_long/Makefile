CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX = -I /usr/local/include/ -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit
NAME = so_long

SRCS = src/main.c \
		src/get_next_line/get_next_line.c \
		src/init.c src/draw.c src/error.c \
		src/map.c

OBJS = $(SRCS:.c=.o)

.PHONY: all
all:  $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(MLX) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf $(OBJS)

.PHONY: fclean
fclean: clean
	rm -rf $(NAME) $(OBJS)

.PHONY: re
re: fclean all
