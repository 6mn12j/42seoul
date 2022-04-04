CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude
PTHREAD = -pthread
NAME = philo

SRCS = src/main.c \
		src/init.c \
		src/time.c \
		src/utils.c \
		src/monitor.c \
		src/routine.c \
		src/libft.c \

OBJS = $(SRCS:.c=.o)

.PHONY: all
all:  $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(PTHREAD) -o $(NAME) $(OBJS)

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
