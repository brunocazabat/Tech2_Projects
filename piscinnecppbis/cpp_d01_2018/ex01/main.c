/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include "menger.h"

int main(int ac, char **av)
{
        if (ac != 3 || !is_digit(av[1]) || !is_digit(av[2]))
                return (84);
        int size = atoi(av[1]);
        int level = atoi(av[2]);
        if (size < level * level * level)
                return (84);
        printf("%03d %03d %03d\n", size / 3, size / 3, size /3);
        if (level > 1)
            menger(size / 3);
        return (0);
}