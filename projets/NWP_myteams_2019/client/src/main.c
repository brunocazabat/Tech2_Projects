/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#include "../include/client.h"

my_client *clistruct_init(void)
{
    my_client *cli = malloc(sizeof(my_client));

    if (!cli)
        return (NULL);

    //INIT ALL STRUCT VALUE HERE
    cli->port   = 0;
    cli->ip     = NULL;

    return (cli);
}

int main_handler(int ac, char **av)
{
    if (ac != 2 && ac != 3)
        return (ERROR);
    if (ac == 2) {
        if (strcmp(av[1], "-help\0") == 0) {
            print_usage();
            return (CORRECT);
        }
        return (ERROR);
    }
    return (CORRECT);
}

int main(int ac, char **av)
{
    my_client   *cli;

    if (main_handler(ac, av) == ERROR) {
        fprintf(stderr, "ERROR: BAD ARGUMENTS, USE -help.\n");
        return (ERROR);
    }

    if (ac == 3) {
        cli = clistruct_init();
        if (check_args(cli, av) == ERROR) {
            printf("ERROR 1");
            return (ERROR);
        } else if (connect_to_socket(cli) == 1) {
            cli_loop(cli);
            free (cli);
            return (CORRECT);
        } else {
            free (cli);
            return (ERROR);
        }
    }
}