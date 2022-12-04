/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#include <iostream>
#include "my_core/include/ArgParser.hpp"
#include "my_core/include/GraphLibLoader.hpp"
#include "my_core/include/Core.hpp"

void print_usage()
{
    std::cerr << "Wrong Usage, please use one of the two flags with the program :" << std::endl;
    std::cerr << "  ./arcade libs/lib_arcade_NCURSES.so  (for an NCURSES interface)" << std::endl;
    std::cerr << "   OR" << std::endl;
    std::cerr << "  ./arcade libs/lib_arcade_SFML.so     (for an SFML complex interface)" << std::endl;
	std::cerr << "   OR" << std::endl;
    std::cerr << "  ./arcade libs/lib_arcade_SDL.so      (for an SDL complex interface)" << std::endl;
}

int main(int ac, char **av)
{
	int bruh = 0;

	if ((bruh = Arcade::ArgParser::parseArgs(ac, av)) != 0)
		print_usage();

	if (bruh == 0) {
		Arcade::Core core(av[1]);
		return core.startArcade();
	}
	
	return bruh;
}