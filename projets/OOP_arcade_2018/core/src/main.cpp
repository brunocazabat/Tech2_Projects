/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/

#include "../include/include.hpp"

using namespace::std;

void print_usage()
{
    cerr << "Wrong Usage, please use one of the two flags with the program :" << std::endl;
    std::cerr << "  ./lib_arcade_NCURSES.so  (for an NCURSES interface)" << std::endl;
    std::cerr << "   OR" << std::endl;
    std::cerr << "  ./lib_arcade_SFML.so     (for an SFML complex interface)" << std::endl;
}

int main(int ac, char **av)
{
    maker_arcade pMaker;
    void *mkr;
    void *handle;

    //OPEN
    handle = dlopen(av[1], RTLD_LAZY);
    std::cout << av[1] << std::endl;
    if (!handle || ac != 2) {
        cerr << "Cannot open library: " << dlerror() << endl;
        return (84);
    }

    //READ
    mkr = dlsym(handle, "make_arcade");
    if (mkr == NULL)    {
		cerr << "Dlsym cannot read library : " << dlerror() << endl;
		return (84);
    }
    pMaker = (maker_arcade)mkr;
    arcade *my_arcade = pMaker();

    //START ARCADE NCURSES
    if(strcmp(av[1], "./lib_arcade_NCURSES.so") == 0) {
        my_arcade->start();
        //text_start(&data);
        return (0);
    }

    //START ARCADE SFML
    if (strcmp(av[1], "./lib_arcade_SFML.so") == 0) {
        my_arcade->start();
        return (0);
    }

    else
        print_usage();
    dlclose(handle);
    return (84);
}