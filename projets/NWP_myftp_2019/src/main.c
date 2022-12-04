/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#include "server.h"

int         main_handler(int ac, char **av)
{
    if (ac != 2 && ac != 3)
        return (ERROR);
    if (ac == 2) {
        if (strcmp(av[1], "-help\0") == 0) {
            print_usage();
            return (CORECT);
        }
        return (ERROR);
    }
    return (CORECT);
}

int         main(int ac, char **av)
{
    my_ftp   *ftp;

    if (main_handler(ac, av) == ERROR) {
        fprintf(stderr, "ERROR: BAD ARGUMENTS, USE -help.\n");
        return (ERROR);
    }
    if (ac == 3) {
        ftp = ftpstruct_init();
        if (check_args(ftp, av) == ERROR || !ftp)
            return (ERROR);
        else if (init_serv(ftp) != ERROR) {
            handle_server(ftp);
            free (ftp);
            return (CORECT);
        } else {
            free (ftp);
            return (ERROR);
        }
    }
}