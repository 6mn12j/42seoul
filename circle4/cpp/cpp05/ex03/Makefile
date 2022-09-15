CC = c++
CFLAGS = -Wall -Wextra -Werror -I./ -std=c++98
NAME = ex03

SRCS =  ./main.cpp \
		./Bureaucrat.cpp \
		./Intern.cpp \
		./Form.cpp \
		./ShrubberyCreationForm.cpp \
		./RobotomyRequestForm.cpp \
		./PresidentialPardonForm.cpp \

OBJS = $(SRCS:.cpp=.o)

.PHONY: all
all:  $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

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
