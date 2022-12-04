/*
** EPITECH PROJECT, 2019
** SYN_abstractVM_2018
** File description:
** main
*/

#include "../include/Parser.hpp"

int main(int ac, char **av)
{
    Parser s;

    if (ac == 1) {
        if (s.readinit(av[0], 0) == 84)
            return (84);
    }
    if (ac == 2) {
	    if (s.readinit(av[1], 1) == 84)
            return (84);
    }
    if (ac < 2 || ac > 2) {
        return 84;
    }
    return (0);
}