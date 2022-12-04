/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#include "../include/client.h"

void        print_usage(void)
{
    printf("USAGE: ./myteams_cli ip port\n");
    printf("\tip is the server ip address on which \
        the server socket listens\n");
    printf("\tport is the port number on which the server socket listens\n");
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
    return (CORRECT);
}

int         ip_check(char *str)
{
    int i = 0;
    int j = 0;

    if (strcmp(str, "localhost") == 0)
        return (CORRECT);
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

int         check_args(my_client *cli, char **av)
{
    if (!cli)
        return (ERROR);
    if (ip_check(av[1]) == ERROR) {
        fprintf(stderr, "IP IS NOT VALID\n");
        return (ERROR);
    }
    if (port_check(av[2]) == ERROR) {
        fprintf(stderr, "PORT IS NOT VALID\n");
        return (ERROR);
    }
    
    cli->ip     = strdup(av[1]);
    cli->port   = atoi(av[2]);
    
    return (CORRECT);
}