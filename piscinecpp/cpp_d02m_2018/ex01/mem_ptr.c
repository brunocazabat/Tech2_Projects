/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/
#include <string.h>
#include "mem_ptr.h"

void add_str(const char *str1, const char *str2, char **res)
{
    char *str_clone1 = strdup(str1);
    char *str_clone2 = strdup(str2);

    *res = strcat(str_clone1, str_clone2);
}

void add_str_struct(str_op_t *str_op)
{
    char *str_clone1 = strdup(str_op->str1);
    char *str_clone2 = strdup(str_op->str2);

    str_op->res = strcat(str_clone1, str_clone2);
}
