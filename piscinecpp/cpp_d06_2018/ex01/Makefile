##
## EPITECH PROJECT, 2019
## ouioui
## File description:
## oui
##

NAME	= my_convert_temp

CC	= g++

RM	= rm -f

SRCS	= ./temp_conv.cpp 

OBJS	= $(SRCS:.cpp=.o)

CPPFLAGS = -I 
CPPFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re