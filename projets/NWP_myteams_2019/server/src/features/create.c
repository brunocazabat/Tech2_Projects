/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#include "../../include/server.h"

void        _create(char **stack, my_server *s)
{
    (void)stack;
    (void)s;
    
    write(1, "Command /create received\n", 26);

    return;
}