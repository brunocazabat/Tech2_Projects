/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#include "../../include/client.h"

void        _users(char **stack, my_client *s)
{
    (void) stack;

    send(s->sock, "/users", strlen("/users"), 0);

    return;
}