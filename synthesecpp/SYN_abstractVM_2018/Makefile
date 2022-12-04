##
## EPITECH PROJECT, 2019
## ouioui
## File description:
## oui
##

NAME	= abstractVM

CC		= g++

RM		= rm -f

SRCS	= 	./src/main.cpp 		\
			./src/Exception.cpp \
			./src/Parser.cpp

OBJS	= $(SRCS:.cpp=.o)

CPPFLAGS = -I ./include/pp

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(CPPFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
