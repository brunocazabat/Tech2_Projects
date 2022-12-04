##
## EPITECH PROJECT, 2020
## ouioui
## File description:
## oui
##

CC 		= 	g++
RM 		= 	rm -f
TARGET_LIB 	= 	lib_arcade_SFML.so

SRCS		= 	./src/entryPoint.cpp			\
			./src/LibSFML.cpp					\
			../../../my_core/src/TextBox.cpp		\
			../../../my_core/src/PixelBox.cpp		\
			../../../my_core/src/Color.cpp

OBJS 		= 	$(SRCS:.cpp=.o)

CXXFLAGS 	= 	-I. -I ../../../my_core/include
CXXFLAGS 	+= 	-W -Wall -Wextra -fPIC
LDFLAGS      	=	-shared -lsfml-graphics -lsfml-window -lsfml-system -rdynamic -std=c++11

all: $(TARGET_LIB)

$(TARGET_LIB): $(OBJS)
	 $(CC) $(OBJS) -o ../../$(TARGET_LIB) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) ../../$(TARGET_LIB)

re: fclean all

.PHONY: all clean fclean re
