/*
** EPITECH PROJECT, 2019
** info
** File description:
** info
*/

#include "simple_list.h"
#include <stdio.h>
#include <stdlib.h>

unsigned int list_get_size(list_t list)
{
    unsigned int i = 0;

    while (list != NULL) {
        list = list->next;
        i++;
    }
    return (i);
}

bool_t list_is_empty(list_t list)
{
    if (list_get_size(list) == 0)
        return (TRUE);
    return (FALSE);
}

void list_dump(list_t list)
{
    while (list != NULL) {
        printf("%f\n", list->value);
        list = list->next;
    }
}