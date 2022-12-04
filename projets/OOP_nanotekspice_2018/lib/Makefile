##
## EPITECH PROJECT, 2019
## ouioui
## File description:
## oui
##

CXX		=	g++

NAME		=	../libnanotekspice.a

RM		=	rm -f

SRCSDIR		+=	./src/
EXCEPTDIR	+=	$(SRCSDIR)exception/
CMPTDIR		+=	$(SRCSDIR)component/
PARSERDIR	+=	$(SRCSDIR)parser/

CXXFLAGS	+=	-std=c++11
CXXFLAGS	+=	-W -Wall -Wextra -Werror
CXXFLAGS	+=	-I./include/

SRCS		+=	$(SRCSDIR)Circuit.cpp
SRCS		+=	$(SRCSDIR)Nanotekspice.cpp
SRCS		+=	$(EXCEPTDIR)Exception.cpp
SRCS		+=	$(PARSERDIR)ASTParser.cpp
SRCS		+=	$(CMPTDIR)ComponentManager.cpp
SRCS		+=	$(CMPTDIR)Input.cpp
SRCS		+=	$(CMPTDIR)True.cpp
SRCS		+=	$(CMPTDIR)False.cpp
SRCS		+=	$(CMPTDIR)Clock.cpp
SRCS		+=	$(CMPTDIR)Output.cpp
SRCS		+=	$(CMPTDIR)C4071.cpp
SRCS		+=	$(CMPTDIR)C4081.cpp
SRCS		+=	$(CMPTDIR)C4069.cpp
SRCS		+=	$(CMPTDIR)C4001.cpp
SRCS		+=	$(CMPTDIR)C4011.cpp
SRCS		+=	$(CMPTDIR)C4030.cpp
SRCS		+=	$(CMPTDIR)C4008.cpp
SRCS		+=	$(CMPTDIR)C4013.cpp
SRCS		+=	$(CMPTDIR)C4017.cpp
SRCS		+=	$(CMPTDIR)C4040.cpp
SRCS		+=	$(CMPTDIR)C4094.cpp
SRCS		+=	$(CMPTDIR)C4514.cpp
SRCS		+=	$(CMPTDIR)C4801.cpp
SRCS		+=	$(CMPTDIR)C2716.cpp

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
