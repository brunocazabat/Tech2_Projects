##
## EPITECH PROJECT, 2020
## ouioui
## File description:
## oui
##

NAME	= myftp

CC	= gcc

RM	= rm -f

SRCS	= ./src/errorhandler.c \
	  ./src/fucking_pasv.c \
	  ./src/main.c \
	  ./src/request_func1.c \
	  ./src/request_func2.c \
	  ./src/request_func3.c \
	  ./src/request_func4.c \
	  ./src/request_func5.c \
	  ./src/request_func6.c \
	  ./src/server.c \
	  ./src/utilsclientfunc.c \
	  ./src/utilsserverfunc.c \

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/
CFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
