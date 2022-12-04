/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#include "../../include/server.h"

void        _help(char **stack, my_server *s)
{
    (void)stack;
    (void)s;
    
    write(1, "Command /help received\n", 24);

    return;
}
