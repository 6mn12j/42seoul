CC = c++
CPPFLAGS = -Wall -Wextra -Werror -I./includes -std=c++98
NAME = PhoneBook

SRCS =  ./srcs/main.cpp \
		./srcs/PhoneBook.cpp \
		./srcs/Contact.cpp

OBJS = $(SRCS:.cpp=.o)

.PHONY: all
all:  $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CPPFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf $(OBJS)

.PHONY: fclean
fclean: clean
	rm -rf $(NAME) $(OBJS)

.PHONY: re
re: fclean all
