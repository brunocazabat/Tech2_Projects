/*
** EPITECH PROJECT, 2019
** 01
** File description:
** 01
*/

#include "mem_ptr.h"
#include <stdio.h>
#include <string.h>

void add_str(const char *str1, const char *str2, char **res)
{
    char *new_str = strdup(str1);

    new_str = strcat(new_str, str2);
    *res = new_str;
}

void add_str_struct(str_op_t *str_op)
{
    char *new_str = strdup(str_op->str1);
    
    new_str = strcat(new_str, str_op->str2);
    str_op->res = new_str;
}