##
## EPITECH PROJECT, 2019
## ouioui
## File description:
## oui
##

NAME	= myftp

CC	= gcc

RM	= rm -f

SRCS	= ./src/init_struct.c \
	  ./src/main.c 

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/
CFLAGS += -W -Wall -Wextra -Wundef -Wpointer-arith -Wcast-align -Wcast-qual -Wunreachable-code -g3
##CFLAGS += -Werror

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
