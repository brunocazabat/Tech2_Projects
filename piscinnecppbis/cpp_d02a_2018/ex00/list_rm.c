/*
** EPITECH PROJECT, 2019
** del
** File description:
** del
*/

#include "simple_list.h"
#include <stdio.h>
#include <stdlib.h>

bool_t list_del_elem_at_front(list_t *front_ptr)
{
    list_t tmp = *front_ptr;

    if (tmp == NULL)
        return (FALSE);
    tmp = tmp->next;
    *front_ptr = tmp;
    return (TRUE);
}

bool_t list_del_elem_at_back(list_t *front_ptr)
{
    list_t current = *front_ptr;

    if (current == NULL)
        return (FALSE);
    if (current->next == NULL)
        return (list_del_elem_at_front(front_ptr));
    while (current->next->next != NULL)
        current = current->next;
    free(current->next);
    current->next = NULL;
    return (TRUE);
}

bool_t list_del_elem_at_position(list_t *front_ptr, unsigned int position)
{
    unsigned int i = 0;
    list_t current = *front_ptr;
    list_t del;

    if (position == 0)
        return (list_del_elem_at_front(front_ptr));
    if (position >= list_get_size(*front_ptr))
        return (FALSE);
    while (i < position - 1) {
        i++;
        current = current->next;
    }
    if (position == list_get_size(*front_ptr))
        return (list_del_elem_at_back(front_ptr));
    del = current->next;
    current->next = current->next->next;
    free(del);
    return (TRUE);
}