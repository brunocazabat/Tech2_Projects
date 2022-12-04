##
## EPITECH PROJECT, 2020
## ouioui
## File description:
## oui
##

NAME	= 		myteams_server

CC		= gcc

RM		= rm -f

SRCS	=  	./src/main.c 				\
			./src/usefull_func.c		\
			./src/error_handler.c		\
			./src/server_init.c			\
			./src/handle_server.c		\
			./src/request_handler.c		\
			./src/features/create.c		\
			./src/features/help.c		\
			./src/features/info.c		\
			./src/features/list.c		\
			./src/features/login.c		\
			./src/features/logout.c		\
			./src/features/messages.c		\
			./src/features/send.c		\
			./src/features/subscribe.c		\
			./src/features/subscribedlist.c		\
			./src/features/unsubscribe.c		\
			./src/features/use.c		\
			./src/features/user.c		\
			./src/features/userslist.c		\

OBJS	= $(SRCS:.c=.o)

CFLAGS 	= -I ./include/
CFLAGS 	+= -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o ../$(NAME)  -L../libs/myteams -lmyteams $(LDFLAGS)
	export LD_LIBRARY_PATH=../libs/myteams:$LD_LIBRARY_PATH

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) ../$(NAME)

re: fclean all

.PHONY: all clean fclean re
