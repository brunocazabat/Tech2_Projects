/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#include "../../include/client.h"

void        _user(char **stack, my_client *s)
{
    (void) stack;

    send(s->sock, "/user", strlen("/user"), 0);

    return;
}