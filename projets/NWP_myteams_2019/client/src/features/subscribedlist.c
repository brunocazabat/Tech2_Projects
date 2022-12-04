/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#include "../../include/client.h"

void        _subscribed(char **stack, my_client *s)
{
    (void) stack;

    send(s->sock, "/subscribed ?", strlen("/subscribed ?"), 0);

    return;
}