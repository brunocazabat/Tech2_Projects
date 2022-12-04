/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#include "../../include/client.h"

void        _send(char **stack, my_client *s)
{
    (void) stack;

    send(s->sock, "/send", strlen("/send"), 0);

    return;
}