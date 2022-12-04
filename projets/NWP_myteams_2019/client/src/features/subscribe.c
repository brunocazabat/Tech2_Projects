/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#include "../../include/client.h"

void        _subscribe(char **stack, my_client *s)
{
    (void) stack;

    send(s->sock, "/subscribe", strlen("/subscribe"), 0);

    return;
}