/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#include "server.h"

int         init_port2(my_client *cli, char **stack, SOCK_IN *sock_in)
{
    char *ip = get_ip(stack);
    SOCKLEN size = sizeof(*sock_in);

    sock_in->sin_port = htons(atoi(stack[4]) * 256 + atoi(stack[5]));
    sock_in->sin_family = AF_INET;
    sock_in->sin_addr.s_addr = inet_addr(ip);
    if (connect(cli->fd_mod, (SOCK *)sock_in, size) == -1)
        return (1);
    free_tab(stack);
    dprintf(cli->fd, "200 PORT command sucess.\n");
    cli->pasv_mod = 2;
    free(ip);
    return (0);
}

int         init_port(char **stack, my_client *cli, BRUH *prot_entry)
{
    SOCK_IN sock_in;

    if (cli->fd_mod != -1)
        close(cli->fd_mod);
    prot_entry = getprotobyname("TCP");
    if (prot_entry == NULL)
        return (1);
    cli->fd_mod = socket(AF_INET, SOCK_STREAM, prot_entry->p_proto);
    if (cli->fd_mod == -1)
        return (1);
    return (init_port2(cli, stack, &sock_in));
}

void        open_port(char **stack, my_client *cli, BRUH *prot_entry)
{
    char **cmd = str_wordtab(stack[1], ", \n");

    if (!cmd || port_check_tab(cmd) == ERROR)
        dprintf(cli->fd, "500 Requested action not taken.\n");
    else
        if (init_port(cmd, cli, prot_entry) == 1)
            dprintf(cli->fd, "500 Requested action not taken.\n");
}