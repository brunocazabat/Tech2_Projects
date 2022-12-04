##
## EPITECH PROJECT, 2019
## cazabat/mayet
## File description:
## malloc
##

CC	=	gcc

RM	=	rm -f

NAME	=	libmy_malloc_$(HOSTTYPE).so

LINK	=	libmy_malloc.so

CFLAGS	=	-Wall -Wextra -fPIC

SRC	=	malloc.c		

OBJ	=	$(SRC:.c=.o)

$(NAME)	:	$(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -shared -o $(NAME)
		ln -sf $(NAME) $(LINK)

all	:	$(NAME)

clean	:
		$(RM) $(OBJ)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all
