/*
** EPITECH PROJECT, 2019
** elem
** File description:
** elem
*/

#include "simple_list.h"
#include <stdio.h>
#include <stdlib.h>

double list_get_elem_at_front(list_t list)
{
    if (list_is_empty(list))
        return (0);
    return (list->value);
}

double list_get_elem_at_back(list_t list)
{
    if (list_is_empty(list))
        return (0);
    while (list->next != NULL)
        list = list->next;
    return (list->value);
}

double list_get_elem_at_position(list_t list, unsigned int position)
{
    int unsigned i = 0;

    if (position == 0)
        return (list_get_elem_at_front(list));
    if (position >= list_get_size(list))
        return (0);
    while (i < position) {
        list = list->next;
        i++;
    }
    return (list->value);
}

node_t *list_get_first_node_with_value(list_t list, double value)
{
    if (list_is_empty(list))
        return (NULL);
    while (list->value != value) {
        list = list->next;
        if (list == NULL)
            return (NULL);
    }
    return (list);
}