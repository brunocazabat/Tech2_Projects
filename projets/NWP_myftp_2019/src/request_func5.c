/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#include "server.h"

void        noop(char **stack, my_client *iencli)
{
    (void)stack;

    if (iencli->log <= CORECT)
        dprintf(iencli->fd, "530 Not logged in.\n");
    else
        dprintf(iencli->fd, "200 NOOP.\n");
}

void        retr(char **stack, my_client *iencli)
{
    if (iencli->log < MAGIC_WRD)
        dprintf(iencli->fd, "530 Not logged in.\n");
    else {
        if (iencli->pasv_mod == CORECT)
            dprintf(iencli->fd, "425 Can't open data connection\n");
        else
            exec_retr(stack, iencli);
    }
}

void        stor(char **stack, my_client *iencli)
{
    if (iencli->log < MAGIC_WRD)
        dprintf(iencli->fd, "530 Not logged in.\n");
    else {
        if (iencli->pasv_mod == CORECT)
            dprintf(iencli->fd, "425 Can't open data connection\n");
        else
            exec_stor(stack, iencli);
    }
}

void        list(char **stack, my_client *iencli)
{
    (void)stack;

    if (iencli->log < MAGIC_WRD)
        dprintf(iencli->fd, "530 Not logged in.\n");
    else {
        if (iencli->pasv_mod == CORECT)
            dprintf(iencli->fd, "425 Can't open data connection\n");
        else {
            dprintf(iencli->fd, "150 File status okay.\n");
            exec_list(iencli);
        }
    }
}