##
## EPITECH PROJECT, 2019
## SYN_jetpack2Tek3_2018
## File description:
## Makefile
##


SRC1	=	src/server.c		\
		src/parse.c			\
		src/main.c	\
		src/usefull_func.c	\
		src/proto_parser.c	\
		src/init_var.c	\
		src/move.c		\
		src/display.c

OBJ1=	$(SRC1:.c=.o)

RM	=	rm -f

NAME1	=	serverJ2T3

all: $(NAME1)
	cp serverJ2T3 ..

$(NAME1): $(OBJ1)
	gcc -o $(NAME1) $(OBJ1) -Wall -Wextra -Werror -pthread

clean:
	$(RM) $(OBJ1)

fclean: clean
	$(RM) $(NAME1)

re: 	fclean all
