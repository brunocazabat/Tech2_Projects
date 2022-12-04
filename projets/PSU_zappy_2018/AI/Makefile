##
## EPITECH PROJECT, 2019
## ouioui
## File description:
## oui
##

NAME	= zappy_ai

CC		= g++

RM		= rm -f

SRCS	= 		./src/main_IA.cpp 			\
	  			./src/inputma_IA.cpp 		\
	  			./src/usefull_fonctions.cpp \
				./src/usefull_fonctions2.cpp\
				./src/usefull_fonctions3.cpp\
				./src/brain_IA.cpp			\
				./src/allsend_IA.cpp		\
				./src/allsend_IA2.cpp			

OBJS	= 		$(SRCS:.cpp=.o)

CPPFLAGS = 		-I ./include/pp
CPPFLAGS += 	-Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
