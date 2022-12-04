##
## EPITECH PROJECT, 2020
## ouioui
## File description:
## oui
##

CC 		= 	g++
RM 		= 	rm -f
TARGET_LIB 	= 	lib_arcade_ncurses.so

SRCS		= 	./src/entryPoint.cpp			\
			./src/LibNcurses.cpp				\
			../../../my_core/src/TextBox.cpp		\
			../../../my_core/src/PixelBox.cpp		\
			../../../my_core/src/Color.cpp

OBJS 		= 	$(SRCS:.cpp=.o)

CXXFLAGS 	= 	-I. -I ../../../my_core/include
CXXFLAGS 	+= 	-W -Wall -Wextra -fPIC -rdynamic -std=c++11
LDFLAGS      	=	-shared -lncurses

all: $(TARGET_LIB)

$(TARGET_LIB): $(OBJS)
	 $(CC) $(OBJS) -o ../../$(TARGET_LIB) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) ../../$(TARGET_LIB)

re: fclean all

.PHONY: all clean fclean re
