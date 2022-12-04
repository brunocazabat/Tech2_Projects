/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#include "../../include/server.h"

void        _subscribed(char **stack, my_server *s)
{
    (void)stack;
    (void)s;
    
    write(1, "Command /subscribed ? received\n", 32);

    return;
}