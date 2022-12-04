/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#include "../../include/client.h"

void        _help(char **stack, my_client *s)
{
    (void) stack;

    send(s->sock, "/help", strlen("/help"), 0);
    
    return;
}
