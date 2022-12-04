/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#include "../../include/client.h"

void        _create(char **stack, my_client *s)
{
    (void) stack;

    send(s->sock, "/create", strlen("/create"), 0);

    return;
}