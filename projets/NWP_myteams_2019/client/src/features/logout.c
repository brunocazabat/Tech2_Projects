/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#include "../../include/client.h"

void        _logout(char **stack, my_client *s)
{
    (void) stack;

    send(s->sock, "/logout", strlen("/logout"), 0);

    return;
}