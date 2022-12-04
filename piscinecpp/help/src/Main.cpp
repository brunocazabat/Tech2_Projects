/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/

#include "Graphical.hpp"

Graphical::Graphical()
{
}

Graphical::~Graphical()
{
}

void printerror()
{
    std::cerr << "Wrong Usage, please use one of the two flags with the program :" << std::endl;
    std::cerr << "  --text/-t  (for an basic interface) OR   --graphical/-g  (for an much complex interface) OR --help/-h (for help)" << std::endl;
}

void help_exec()
{
	std::cout << "HOW TO USE OUR EXECTUBALE!!\n./program -t or --text for ncurses \n ./program -g or --graphical for the SFML \n ./program -h or --help for the HELP" << std::endl;

}
int main(int ac, char const **av)
{
    Graphical_t data;
	const char *textparam = "--text";
	const char *graphparam = "--graphical";
	const char *text = "-t";
	const char *graphical = "-g";
	const char *helpparam = "--help";
	const char *help = "-h";

    if (ac != 2) {
        printerror();
        return 84;
    }
    if (strcmp(av[1], textparam) == 0 || strcmp(av[1], text) == 0)
        text_init(&data);
    else if (strcmp(av[1], graphparam) == 0 || strcmp(av[1], graphical) == 0)
        graphical_init();
    else if (strcmp(av[1], helpparam) == 0 || strcmp(av[1], help) == 0)
	    help_exec();
    else {
        printerror();
        return 84;
    }

    return 0;
}
