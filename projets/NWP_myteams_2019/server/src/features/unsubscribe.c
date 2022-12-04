/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#include "../../include/server.h"

void        _unsubscribe(char **stack, my_server *s)
{
    (void)stack;
    (void)s;
    
    write(1, "Command /unsubscribe received\n", 31);

    return;
}