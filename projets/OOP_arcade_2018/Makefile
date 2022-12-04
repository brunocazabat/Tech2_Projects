##
## EPITECH PROJECT, 2019
## ouioui
## File description:
## oui
##

NAME	= arcade

CC	= g++

RM	= rm -f

SRCS	= 	./core/src/main.cpp 

OBJS	= $(SRCS:.cpp=.o)

CPPFLAGS = -I ./core/include/pp
CPPFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	make all -C ./lib
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS) -ldl
	

clean:
	$(RM) $(OBJS)
	make fclean -C ./lib

fclean:
	$(RM) $(NAME)
	make fclean -C ./lib

re: fclean all

.PHONY: all clean fclean re
