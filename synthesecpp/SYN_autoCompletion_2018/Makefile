##
## EPITECH PROJECT, 2019
## ouioui
## File description:
## oui
##

NAME	= 	autoCompletion

CC		= 	g++ -g3

RM		= 	rm -f

SRCS	= 	./src/main.cpp 				\
	  		./src/structinit.cpp 		\
	  		./src/testing_str.cpp 		\
			./src/parser.cpp			\
			./src/autoc_brain.cpp

OBJS	= $(SRCS:.cpp=.o)

CPPFLAGS 	= 	-I ./include/pp
CPPFLAGS 	+= 	-Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(CPPFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
