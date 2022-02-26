# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/04 12:47:42 by minjupar          #+#    #+#              #
#    Updated: 2022/02/27 04:32:34 by minjupar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SERVER = server
CLIENT = client

INCLUDES = minitalk.h

SERVER_SRCS = server.c utils.c
CLIENT_SRCS = client.c utils.c

OBJ_SERVER = $(SERVER_SRCS:.c=.o)
OBJ_CLIENT = $(CLIENT_SRCS:.c=.o)


.PHONY: all
all: $(SERVER) $(CLIENT)

$(SERVER): $(OBJ_SERVER)
	$(CC) $(CFLAGS) -o $(SERVER) $(OBJ_SERVER)

$(CLIENT): $(OBJ_CLIENT)
	$(CC) $(CFLAGS) -o $(CLIENT) $(OBJ_CLIENT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf $(OBJ_CLIENT) $(OBJ_SERVER)

.PHONY: fclean
fclean: clean
	rm -rf $(CLIENT) $(SERVER)

.PHONY: re
re: fclean all
