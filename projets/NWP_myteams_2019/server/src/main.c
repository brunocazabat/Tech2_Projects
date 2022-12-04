/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#include "../include/server.h"

int             main_handler(int ac, char **av)
{
    if (ac != 2) {
        fprintf(stderr, "ERROR: BAD ARGUMENTS, USE -help.\n");
        return (ERROR);
    }
    
    if (strcmp(av[1], "-help\0") == 0) {
        print_usage();
        return (ERROR);
    }
    return (CORRECT);
}

int             main(int ac, char **av)
{
    my_server   *srv = srvstruct_init(av[1]);

    if (main_handler(ac, av) == ERROR)
        return (ERROR);
    if (check_args(srv, av) == ERROR)
        return (ERROR);
    if (init_serv(srv) != ERROR) {
        printf("Listening on port %d.\nWaiting for connections ...\n", srv->port);
        handle_server(srv);
        free (srv);
        return (CORRECT);
    } else {
        free (srv);
        return (ERROR);
    }
}