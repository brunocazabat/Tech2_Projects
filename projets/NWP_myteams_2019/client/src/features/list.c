/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#include "../../include/client.h"

void        _list(char **stack, my_client *s)
{
    (void) stack;

    send(s->sock, "/list", strlen("/list"), 0);

    return;
}