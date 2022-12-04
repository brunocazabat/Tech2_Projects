##
## EPITECH PROJECT, 2017
##Makefile
## File description:
## Makefile
##

SRC1	=	client/src/error_func.c \
			client/src/all_send.c	\
			client/src/game_init.c	\
			client/src/menu_init.c	\
			client/src/proto_parser.c	\
			client/src/sock_func.c	\
			client/src/usefull_func.c	\
	  		client/src/main.c \
	  		client/src/sfml_func.c 

SRC2	=	server/src/server.c		\
		server/src/parse.c			\
		server/src/main.c	\
		server/src/usefull_func.c	\
		server/src/proto_parser.c	\
		server/src/init_var.c	\
		server/src/move.c		\
		server/src/display.c

OBJ1=	$(SRC1:.c=.o)
OBJ2=   $(SRC2:.c=.o)

RM	=	rm -f

NAME1	=	clientJ2T3
NAME2	=	serverJ2T3

all: $(NAME1) $(NAME2)

server: $(NAME2)

client: $(NAME1)

$(NAME1): $(OBJ1)
	cd client/ && make
	gcc -o $(NAME1) $(OBJ1) -Wall -Wextra -Werror -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -pthread

$(NAME2): $(OBJ2)
	cd server && make
	gcc -o $(NAME2) $(OBJ2) -Wall -Wextra -Werror -pthread
clean:
	$(RM) $(OBJ1) $(OBJ2)

fclean: clean
	$(RM) $(NAME1) $(NAME2)

re: 	fclean all
