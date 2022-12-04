##
## EPITECH PROJECT, 2020
## ouioui
## File description:
## oui
##

CXX		=	g++

NAME		=	nanotekspice

RM		=	rm -f

CXXFLAGS	+=	-std=c++11
CXXFLAGS	+=	-Werror -Wall -Wextra
CXXFLAGS	+=	-I./nano/include/

LDFLAGS		+=	-L./ -lnanotekspice

SRCS		=	./main.cpp

OBJS		=	$(SRCS:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		make -C ./nano/
		$(CXX) $(OBJS) $(CXXFLAGS) $(LDFLAGS) -o $(NAME)

clean:
		make clean -C ./nano/
		$(RM) $(OBJS)

fclean:		clean
		make fclean -C ./nano/
		$(RM) $(NAME)

re:		fclean all