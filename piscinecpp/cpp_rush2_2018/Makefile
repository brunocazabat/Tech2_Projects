NAME	=	SANTA_USINE

CC	=	g++

RM	=	rm -f

SRCS	=	Box.cpp \
			GiftPaper.cpp \
			IConveyorBelt.cpp \
			ITable.cpp \
			LittlePony.cpp \
			MyUnitTests.cpp \
			Object.cpp \
			Teddy.cpp \
			Toy.cpp \
			Wrap.cpp \
			PapaXmasConveyorBelt.cpp \
			PapaXmasTable.cpp

OBJS	=	$(SRCS:.cpp=.o)

CFLAGS	=	-I
CFLAGS	+=	-W -Wall -Wextra -std=c++98

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
