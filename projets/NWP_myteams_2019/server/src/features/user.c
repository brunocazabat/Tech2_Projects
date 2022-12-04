/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#include "../../include/server.h"

void        _user(char **stack, my_server *s)
{
    (void)stack;
    (void)s;
    
    write(1, "Command /user received\n", 24);

    return;
}