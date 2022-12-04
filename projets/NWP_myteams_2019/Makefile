##
## EPITECH PROJECT, 2020
## ouioui
## File description:
## oui
##

all: cli srv

cli:
	make -C ./client
	make clean -C ./client

srv:
	make -C ./server
	make clean -C ./server

clean:
	make clean -C ./client
	make clean -C ./server

fclean: clean
	make fclean -C ./client
	make fclean -C ./server

re: fclean all

.PHONY: all clean fclean re
