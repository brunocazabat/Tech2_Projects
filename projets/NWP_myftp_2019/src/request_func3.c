/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#include "server.h"

void        help(char **stack, my_client *iencli)
{
    (void)stack;

    if (iencli->log <= CORECT)
        dprintf(iencli->fd, "530 Not logged in.\n");
    else
        dprintf(iencli->fd, "214 Help ? Don't see any for you :(\n");
}

void        port(char **stack, my_client *iencli)
{
    BRUH *entry_of_protocol = NULL;

    if (iencli->log < MAGIC_WRD)
        dprintf(iencli->fd, "530 Not logged in.\n");
    else {
        if (!stack[1])
            dprintf(iencli->fd, "500 Requested action not taken\n");
        else
            open_port(stack, iencli, entry_of_protocol);
    }
}

void        pasv(char **stack, my_client *iencli)
{
    BRUH *entry_of_protocol = NULL;
    char *my_ip;
    char **ip;
    (void)stack;

    if (iencli->log < 84)
        dprintf(iencli->fd, "530 Not logged in.\n");
    else {
        if (pasv_mod(iencli, entry_of_protocol) == 1)
            dprintf(iencli->fd, "500 Requested action not taken\n");
        else {
            iencli->pasv_mod = 1;
            my_ip = strdup(iencli->ip);
            ip = str_wordtab(my_ip, ".");
            free(my_ip);
            print_pasv(ip, iencli);
        }
    }
}

void        _pwd(char **stack, my_client *iencli)
{
    char *path;
    (void)stack;

    if (iencli->log <= CORECT)
        dprintf(iencli->fd, "530 Not logged in.\n");
    else {
        path = malloc(sizeof(char) * MALLOC_BRUH);
        getcwd(path, MALLOC_BRUH);
        dprintf(iencli->fd, "257 \"%s\" created\n", path);
        free(path);
    }
}

void        dele(char **stack, my_client *iencli)
{
    if (iencli->log <= CORECT)
        dprintf(iencli->fd, "530 Not logged in.\n");
    else if (stack[1] && remove(stack[1]) == CORECT)
        dprintf(iencli->fd, "250 Requested file action okay.\n");
    else
        dprintf(iencli->fd, "550 Requested action not taken.\n");
}