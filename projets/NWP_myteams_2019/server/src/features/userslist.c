/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#include "../../include/server.h"

void        _users(char **stack, my_server *s)
{
    (void)stack;
    (void)s;
    
    write(1, "Command /users received\n", 25);

    return;
}