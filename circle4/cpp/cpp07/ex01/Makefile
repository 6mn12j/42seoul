CXX = c++
CPPFLAGS = -Wall -Wextra -Werror -I./ -std=c++98
NAME = ex01

SRCS =  ./main.cpp \

OBJS = $(SRCS:.cpp=.o)

HEADER = ./iter.hpp

.PHONY: all
all:  $(NAME) $(HEADER)

$(NAME): $(OBJS) $(HEADER)
	$(CXX) $(CPPFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CXX) $(CPPFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf $(OBJS)

.PHONY: fclean
fclean: clean
	rm -rf $(NAME) 

.PHONY: re
re: fclean all
