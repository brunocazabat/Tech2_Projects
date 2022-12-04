##
## EPITECH PROJECT, 2019
## ouioui
## File description:
## oui
##

NAME	= libstring.a

RM	= rm -f

SRCS	= ./string1.c \
	  ./string2.c \
	  ./string3.c \

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME):$(OBJS)	
	ar rc -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
