/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/

#include "my.h"

int     main (int ac, char **av)
{
	t_data	*data = init_struct();
    data->help = "-help";
    srand(time(NULL));
    signal(SIGCHLD, SIG_IGN);

    if ((ac != 2 && ac != 3 )|| strcmp(data->help, av[1]) != 0 || (is_digit(av[1]) == ERROR_PARAM)) {
        return (ERROR_PARAM);
    }
    if (strcmp(data->help, av[1]) == 0) {
        if (ac == 2)
            print_usage();
        return (0);
    }
    return (0);
}