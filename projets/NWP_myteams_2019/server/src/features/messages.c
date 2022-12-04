/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#include "../../include/server.h"

void        _message(char **stack, my_server *s)
{
    (void)stack;
    (void)s;
    
    write(1, "Command /message received\n", 27);

    return;
}