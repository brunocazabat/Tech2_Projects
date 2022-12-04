/*
** EPITECH PROJECT, 2019
** SYN_jetpack2Tek3_2018
** File description:
** main
*/

# include "../include/server.h"

int main(int ac, char **av)
{
    server_t server;
    int fd;
    if (ac != 7)
        return 84;
    if (check_args(av, &server) == 84)
        return 84;
    init_server_data(&server);
    server_accept(&server);
    printf("END\n");
    return 0;
}