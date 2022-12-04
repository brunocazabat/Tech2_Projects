/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#include "server.h"

void    print_pasv(char **stack, my_client *iencli)
{
    dprintf(iencli->fd, "227 Entering Passive Mode (");
    for (int i = 0; stack[i]; i++)
        dprintf(iencli->fd, "%s, ", stack[i]);
    dprintf(iencli->fd, "%d, %d).\n", iencli->pasv_port / 256, \
        iencli->pasv_port % 256);
    free_tab(stack);
}

int     init_pasv(my_client *iencli, SOCK_IN *my_sock)
{
    SOCKLEN size = sizeof(my_sock);

    my_sock->sin_port = htons(CORECT);
    my_sock->sin_family = AF_INET;
    my_sock->sin_addr.s_addr = INADDR_ANY;
    if (bind(iencli->fd_mod, (CSOCK *)my_sock, \
            sizeof(*my_sock)) == -1) {
        return (1);
    }
    if (listen(iencli->fd_mod, 1) == -1)
        return (1);
    if (getsockname(iencli->fd_mod, (SOCK *)my_sock, &size) == -1)
        return (1);
    iencli->pasv_port = ntohs(my_sock->sin_port);
    return (CORECT);
}

int     pasv_mod(my_client *iencli, BRUH *proto_entry)
{
    SOCK_IN my_sock;

    if (iencli->fd_mod != -1)
        close(iencli->fd_mod);
    proto_entry = getprotobyname("TCP");
    if (proto_entry == NULL)
        return (1);
    iencli->fd_mod = socket(AF_INET, SOCK_STREAM, proto_entry->p_proto);
    if (iencli->fd_mod == -1)
        return (1);
    return (init_pasv(iencli, &my_sock));
}