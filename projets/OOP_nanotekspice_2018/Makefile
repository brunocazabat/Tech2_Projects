##
## EPITECH PROJECT, 2019
## ouioui
## File description:
## oui
##

CXX		=	g++

NAME		=	nanotekspice

RM		=	rm -f

CXXFLAGS	+=	-std=c++11
CXXFLAGS	+=	-Werror -Wall -Wextra
CXXFLAGS	+=	-I./lib/include/

LDFLAGS		+=	-L./ -lnanotekspice

SRCS		=	./main.cpp

OBJS		=	$(SRCS:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		make -C ./lib/
		$(CXX) $(OBJS) $(CXXFLAGS) $(LDFLAGS) -o $(NAME)

clean:
		make clean -C ./lib/
		$(RM) $(OBJS)

fclean:		clean
		make fclean -C ./lib/
		$(RM) $(NAME)

re:		fclean all
