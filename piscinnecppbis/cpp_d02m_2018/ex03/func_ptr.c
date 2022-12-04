/*
** EPITECH PROJECT, 2019
** 03
** File description:
** 03
*/

#include "func_ptr.h"

void print_normal(const char *str)
{
    printf("%s\n", str);
}

void print_reverse(const char *str)
{
    char *rev = strdup(str);
    int i = -1;
    int j = strlen(str);
    int size = strlen(str);

    while (++i < size)
        rev[i] = str[--j];
    printf("%s\n", rev);
}

void print_upper(const char *str)
{
    char *up = strdup(str);
    int i = 0;
    int size = strlen(str);

    for (i = 0; i < size; i++)
        up[i] = toupper(up[i]);
    printf("%s\n", up);
}

void print_42(__attribute__((unused)) const char *str)
{
    printf("42\n");
}

void do_action(action_t action, const char *str)
{
    void (*fct[4])(const char*);
    fct[0] = print_normal;
    fct[1] = print_reverse;
    fct[2] = print_upper;
    fct[3] = print_42;
    (*fct[action])(str);
}