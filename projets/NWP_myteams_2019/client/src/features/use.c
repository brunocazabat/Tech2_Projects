/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#include "../../include/client.h"

void        _use(char **stack, my_client *s)
{
    (void) stack;

    send(s->sock, "/use ?", strlen("/use ?"), 0);

    return;
}