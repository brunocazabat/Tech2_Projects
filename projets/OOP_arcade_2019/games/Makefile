##
## EPITECH PROJECT, 2020
## ouioui
## File description:
## oui
##

all: $(OBJ)
	make -C ./src/Nibbler
	make -C ./src/Pacman

clean:
	make clean -C ./src/Nibbler
	make clean -C ./src/Pacman

fclean: clean
	make fclean -C ./src/Nibbler
	make fclean -C ./src/Pacman

re: fclean all

.PHONY: all clean fclean re
