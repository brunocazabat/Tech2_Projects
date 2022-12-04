##
## EPITECH PROJECT, 2019
## ouioui
## File description:
## oui
##

NAME	= clientJ2T3

CC	= gcc

RM	= rm -f

SRCS	= ./src/error_func.c 	\
	  ./src/menu_init.c 		\
	  ./src/main.c 				\
	  ./src/sfml_func.c			\
	  ./src/game_init.c			\
	  ./src/sock_func.c 		\
	  ./src/all_send.c			\
	  ./src/proto_parser.c		\
	  ./src/usefull_func.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/
CFLAGS += -Wall -Wextra -Wextra -g3 -pthread -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
