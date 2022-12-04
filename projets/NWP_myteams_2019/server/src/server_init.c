/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#include "server.h"

int         init2_serv(my_server *s)
{
    if (bind(s->fd, (CSOCK *)&s->sin, sizeof(s->sin)) < 0) {
        shutdown(s->fd, 2);
        if (close(s->fd) == -1)
            return (ERROR);
        return (ERROR);
    }
    if (listen(s->fd, MAX_CLI) == -1){
        if (close(s->fd) == -1)
            return (ERROR);
        return (ERROR);
    }
    return (CORRECT);
}

int         init_serv(my_server *s)
{
    s->fd = socket(AF_INET, SOCK_STREAM, 0);
    if (s->fd == -1)
        return (ERROR);
    s->sock_size = sizeof(s->sin);
    s->sin.sin_family = AF_INET;
    s->sin.sin_port = htons(s->port);
    s->sin.sin_addr.s_addr = INADDR_ANY;
    if (init2_serv(s) == ERROR)
        return (ERROR);
    return (CORRECT);
}