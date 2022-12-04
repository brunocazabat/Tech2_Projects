/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#include "server.h"

void        print_usage(void)
{
    printf("USAGE: ./myftp port path\n");
    printf("\tport  is the port number on which the server socket listens\n");
    printf("\tpath  is the path to the home directory \
    for the Anonymous user\n");
}

int             port_check_tab(char **stack)
{
    int i = 0;

    while (stack[i])
        i++;
    if (i < 6)
        return (ERROR);
    return (CORECT);
}

int         port_check(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (isdigit(str[i]) == 0)
            return (ERROR);
        i++;
    }
    if (i > 5)
        return (ERROR);
    return (CORECT);
}

int         path_check(char *str)
{
    if (chdir(str) == -1)
        return (ERROR);
    return (CORECT);
}

int         check_args(my_ftp *ftp, char **av)
{
    if (!ftp)
        return (ERROR);
    if (port_check(av[1]) == ERROR) {
        fprintf(stderr, "PORT IS NOT VALID");
        return (ERROR);
    }
    if (path_check(av[2]) == ERROR) {
        fprintf(stderr, "PATH IS NOT VALID");
        return (ERROR);
    }

    ftp->port = atoi(av[1]);
    ftp->path = av[2];
    return (CORECT);
}