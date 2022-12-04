/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#include "../../include/server.h"

void        _list(char **stack, my_server *s)
{
    (void)stack;
    (void)s;
    
    write(1, "Command /list received\n", 24);

    return;
}