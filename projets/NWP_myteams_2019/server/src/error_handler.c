/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#include "../include/server.h"

void            print_usage(void)
{
    printf("USAGE: ./myteams_server path\n");
    printf("\n");
    printf("\tport is the port number on which the server socket listens\n");
}

int             port_check(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (isdigit(str[i]) == 0)
            return (ERROR);
        i++;
    }
    if (i > 5)
        return (ERROR);
    return (CORRECT);
}

int             check_args(my_server *srv, char **av)
{
    if (!srv)
        return (ERROR);
    if (port_check(av[1]) == ERROR) {
        fprintf(stderr, "PORT IS NOT VALID\n");
        return (ERROR);
    }

    return (CORRECT);
}