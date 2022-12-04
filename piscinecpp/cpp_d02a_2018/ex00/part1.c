/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/
#include <simple_list.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

unsigned int list_get_size(list_t list)
{
	int i = 0;

	while (list != NULL) {
		list->next;
		i = i + 1;
	}
	return (i);
}

bool_t list_is_empty(list_t list)
{
	int i = 0;

	while (list != NULL) {
		list->next;
		i = i + 1;
	}
	if (i == 0)
		return (TRUE);
	else
		return (FALSE);
}

void list_dump(list_t list)
{
	while (list != NULL) {
		printf("%f\n", list);
		list->next;
        }
}

void main(void)
{
	list_t list_head = NULL ;

	list_is_empty(list_head);
	list_dump(list_head);
}
