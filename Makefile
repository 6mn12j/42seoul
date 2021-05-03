SRCS = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c

OBJS = ${SRCS:.c=.o}

all: ${OBJS} 
	 gcc -Wall -Wextra -Werror -o ${OBJS} 
