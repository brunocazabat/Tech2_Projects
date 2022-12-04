/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#include "../../include/server.h"

void        _info(char **stack, my_server *s)
{
    (void)stack;
    (void)s;
    
    write(1, "Command /info received\n", 24);

    return;
}