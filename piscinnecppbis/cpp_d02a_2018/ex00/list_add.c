/*
** EPITECH PROJECT, 2019
** add
** File description:
** add
*/

#include "simple_list.h"
#include <stdio.h>
#include <stdlib.h>

bool_t list_add_elem_at_front(list_t *front_ptr, double elem)
{
    list_t new_node = malloc(sizeof(list_t));

    if (!new_node)
        return (FALSE);
    new_node->value = elem;
    new_node->next = *front_ptr;
    *front_ptr = new_node;
    return (TRUE);
}

bool_t list_add_elem_at_back(list_t *front_ptr, double elem)
{
    list_t current = *front_ptr;
    list_t new_element = malloc(sizeof(list_t));

    if (!new_element)
        return (FALSE);
    new_element->value = elem;
    if (list_is_empty(*front_ptr))
        return (list_add_elem_at_front(front_ptr, elem));
    while (current->next != NULL)
        current = current->next;
    current->next = new_element;
    new_element->next = NULL;
    return (TRUE);
}

bool_t list_add_elem_at_position(list_t *front_ptr, double elem, unsigned int position)
{
    unsigned int i = 0;
    list_t current = *front_ptr;
    list_t new_element = malloc(sizeof(list_t));

    if (!new_element)
        return (FALSE);
    if (position == 0)
        return (list_add_elem_at_front(front_ptr, elem));
    if (position > list_get_size(*front_ptr))
        return (FALSE);
    if (position == list_get_size(*front_ptr))
        return (list_add_elem_at_back(front_ptr, elem));
    while (i < position - 1) {
        current = current->next;
        i++;
    }
    new_element->value = elem;
    new_element->next = current->next;
    current->next = new_element;
    return (TRUE);
}