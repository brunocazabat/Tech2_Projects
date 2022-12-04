/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#include "../../include/server.h"

void        _subscribe(char **stack, my_server *s)
{
    (void)stack;
    (void)s;
    
    write(1, "Command /subscribe received\n", 29);

    return;
}