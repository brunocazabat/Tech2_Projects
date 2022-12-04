/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#include "server.h"

void        quit(char **stack, my_client *iencli)
{
    if (stack[CORECT]) {
        dprintf(iencli->fd, "221 Service closing control connection.\n");
        iencli->ret = -1;
    }
}

void        cdup(char **stack, my_client *iencli)
{
    (void)stack;

    if (iencli->log <= CORECT)
        dprintf(iencli->fd, "530 Not logged in.\n");
    else if (path_changer_wdup("../") == 1)
        dprintf(iencli->fd, "550 Requested action not taken.\n");
    else
        dprintf(iencli->fd, "250 Requested file action okay, completed.\n");
}

void        _cwd(char **stack, my_client *iencli)
{
    if (iencli->log <= CORECT)
        dprintf(iencli->fd, "530 Not logged in.\n");
    else if (stack[1] == NULL || path_changer(stack) == 1)
        dprintf(iencli->fd, "550 Requested action not taken.\n");
    else
        dprintf(iencli->fd, "250 Requested file action okay, completed.\n");
}

void        pass(char **stack, my_client *iencli)
{
    if (iencli->log != -MAGIC_WRD) {
        if (iencli->log == MAGIC_WRD)
            dprintf(iencli->fd, "230 Already logged in.\n");
        else if (strcmp(iencli->username, "Anonymous"))
            dprintf(iencli->fd, "530 Not logged in.\n");
        else {
            free(iencli->password);
            dprintf(iencli->fd, "230 User logged in, proceed.\n");
            if (stack[1] != NULL)
                iencli->password = strdup(stack[1]);
            iencli->log = MAGIC_WRD;
        }
    }
    else
        dprintf(iencli->fd, "503 Bad sequence of commands.\n");
}

void        user(char **stack, my_client *iencli)
{
    if (stack[CORECT] && !stack[1] && iencli->log != MAGIC_WRD)
        dprintf(iencli->fd, "530 Not logged in.\n");
    else if (iencli->log == MAGIC_WRD) {
        dprintf(iencli->fd, "530 Not logged in.\n");
    } else {
        free(iencli->username);
        iencli->log = CORECT;
        iencli->username = strdup(stack[1]);
        dprintf(iencli->fd, "331 User name okay, need password.\n");
    }
}