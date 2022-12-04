/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#include "../../include/client.h"

void        _info(char **stack, my_client *s)
{
    (void) stack;

    send(s->sock, "/info", strlen("/info"), 0);

    return;
}