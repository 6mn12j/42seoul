CXX = c++
CFLAGS = -Wall -Wextra -Werror -I./ -std=c++98
NAME = ex02

SRCS =  ./main.cpp \


OBJS = $(SRCS:.cpp=.o)

HEADER =  ./Array.hpp

.PHONY: all
all:  $(NAME)

$(NAME): $(OBJS) $(HEADER)
	$(CXX) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf $(OBJS)

.PHONY: fclean
fclean: clean
	rm -rf $(NAME) $(OBJS)

.PHONY: re
re: fclean all
