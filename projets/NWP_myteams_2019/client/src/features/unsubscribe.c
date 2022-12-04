/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#include "../../include/client.h"

void        _unsubscribe(char **stack, my_client *s)
{
    (void) stack;

    send(s->sock, "/unsubscribe", strlen("/unsubscribe"), 0);

    return;
}