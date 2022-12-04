/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#include "../../include/client.h"

void        _login(char **stack, my_client *s)
{
    (void) stack;

    send(s->sock, "/login", strlen("/login"), 0);

    return;
}