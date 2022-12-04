##
## EPITECH PROJECT, 2019
## ouioui
## File description:
## oui
##

CC 		= 	g++
RM 		= 	rm -f
TARGET_LIB 	= 	lib_arcade_NCURSES.so

SRCS		= 	./lib_ncurses.cpp			\

OBJS 		= 	$(SRCS:.cpp=.o)

CXXFLAGS 	= 	-I. -I ../../../core
CXXFLAGS 	+= 	-W -Wall -Wextra -fPIC
LDFLAGS      	=	-shared -lsfml-graphics -lsfml-window -lsfml-system -rdynamic -std=c++11 -lncurses

all: $(TARGET_LIB)

$(TARGET_LIB): $(OBJS)
	 $(CC) $(OBJS) -o ../../$(TARGET_LIB) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) ../../$(TARGET_LIB)

re: fclean all
