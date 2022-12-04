##
## EPITECH PROJECT, 2020
## ouioui
## File description:
## oui
##

CXX		=	g++

NAME		=	../libnanotekspice.a

RM		=	rm -f

CXXFLAGS	+=	-std=c++11
CXXFLAGS	+=	-W -Wall -Wextra -Werror
CXXFLAGS	+=	-I./include/

SRCS		+=	./src/Circuit.cpp
SRCS		+=	./src/Nanotekspice.cpp
SRCS		+=	./src/component/Exception.cpp
SRCS		+=	./src/component/Parser.cpp
SRCS		+=	./src/component/ComponentManager.cpp
SRCS		+=	./src/component/Input.cpp
SRCS		+=	./src/component/True.cpp
SRCS		+=	./src/component/False.cpp
SRCS		+=	./src/component/Clock.cpp
SRCS		+=	./src/component/Output.cpp
SRCS		+=	./src/component/4071.cpp
SRCS		+=	./src/component/4081.cpp
SRCS		+=	./src/component/4069.cpp
SRCS		+=	./src/component/4001.cpp
SRCS		+=	./src/component/4011.cpp
SRCS		+=	./src/component/4030.cpp
SRCS		+=	./src/component/4008.cpp
SRCS		+=	./src/component/4013.cpp
SRCS		+=	./src/component/4017.cpp
SRCS		+=	./src/component/4040.cpp

OBJS		=	$(SRCS:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)

re:		fclean all

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)
