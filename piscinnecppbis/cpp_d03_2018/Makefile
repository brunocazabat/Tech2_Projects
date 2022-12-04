NAME	= libstring.a

RM	= rm -f

SRCS	=	./string_handle.c \
			./string_info.c \
			./string_assign.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g -g3 -std=gnu11

all: $(NAME)

$(NAME): $(OBJS)
		ar rc $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all