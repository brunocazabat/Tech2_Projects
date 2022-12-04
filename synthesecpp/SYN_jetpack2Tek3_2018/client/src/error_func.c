/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/

#include "../include/include.h"


int             ip_check(char *str)
{
    int i = 0;
    int j = 0;

    if (strcmp(str, "localhost") == 0)
        return (0);
    while (str[i] != '\0') {
        if (str[i] == '.')
            j++;
        else if (isdigit(str[i]) == 0)
            return (ERROR);
        i++;
    }
    if (j != 3)
        return (ERROR);
    return (0);
}

int             port_check(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (isdigit(str[i]) == 0)
            return (ERROR);
        i++;
    }
    return (0);
}

int             error_handler(char **av)
{
    if (strcmp(av[1], "-h") == 0 && strcmp(av[3], "-p") == 0) {
        if (ip_check(av[2]) == ERROR) {
            write(2, "IP IS NOT VALID.\n", 18);
            return (ERROR);
        }
        if (port_check(av[4]) == ERROR) {
            write(2, "PORT IS NOT VALID.\n", 20);
            return (ERROR);
        }
    }
    return (0);
}