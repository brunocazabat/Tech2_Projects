NAME	= zappy_server

CC	= gcc

RM	= rm -f

SRCS	= ./src/options.c \
	  ./src/server.c \
	  ./src/map.c \
	  ./src/commands.c \
	  ./src/player.c \
	  ./src/look.c \
	  ./src/message.c \
	  ./src/broadcast.c \
	  ./src/move.c \
	  ./src/food.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/
CFLAGS += -Wall -Wextra -g -g3

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)
	 cd AI && $(MAKE)
	 cp AI/zappy_ai ../zappy_ai

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
