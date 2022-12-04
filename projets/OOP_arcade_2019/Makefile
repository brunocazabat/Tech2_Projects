##
## EPITECH PROJECT, 2020
## ouioui
## File description:
## oui
##

SRC		=	main.cpp									\
			my_core/src/ArgParser.cpp					\
			my_core/src/GraphLibLoader.cpp				\
			my_core/src/Core.cpp						\
			my_core/src/GameLibLoader.cpp				\
			my_core/src/LogicException.cpp				\
			my_core/src/PixelBox.cpp					\
			my_core/src/TextBox.cpp						\
			my_core/src/Color.cpp						\
			my_core/src/PlayerScore.cpp					\
			my_core/src/MenuManager.cpp					\
			my_core/src/ScoreManager.cpp

CXXFLAGS	=	-I./ -I./my_core/include -I./libs -I./games -W -Wall -Wextra -g -std=c++11 -rdynamic

LIBFLAGS	=	-ldl

OBJ		=	$(SRC:.cpp=.o)

NAME		=	arcade

all: games graphicals core

core: $(OBJ)
	g++ -o $(NAME) $(OBJ) $(LIBFLAGS)

graphicals:
	make -C ./libs

games:
	make -C ./games

clean:
	make clean -C ./libs
	make clean -C ./games
	rm -rf $(OBJ)

fclean: clean
	make fclean -C ./libs
	make fclean -C ./games
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re core graphicals games arcade
