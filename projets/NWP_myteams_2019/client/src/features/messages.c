/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#include "../../include/client.h"

void        _message(char **stack, my_client *s)
{
    (void) stack;

    send(s->sock, "/message", strlen("/message"), 0);

    return;
}