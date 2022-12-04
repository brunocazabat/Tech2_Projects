NAME	= program

CC	= g++

RM	= rm -f

SRCS	= ./src/GraphicalPart.cpp \
	  ./src/Main.cpp \
	  ./src/TextPart.cpp 

OBJS	= $(SRCS:.cpp=.o)

CPPFLAGS = -I ./include/pp
CPPFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS) -lncurses

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
