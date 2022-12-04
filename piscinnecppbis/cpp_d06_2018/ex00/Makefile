NAME	= my_cat

CC	= g++

RM	= rm -f

SRCS	= ./ex00.cpp 

OBJS	= $(SRCS:.cpp=.o)

CPPFLAGS = -I 
CPPFLAGS += -Wall -Wextra -Werror -g -g3

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
