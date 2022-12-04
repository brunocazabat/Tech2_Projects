/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "func_ptr.h"

void print_normal(const char *str)
{
    printf("%s\n", str);
}

void print_reverse(const char *str)
{
    char *my_string = malloc(sizeof(char) * strlen(str));
    int i = 0;
    int j = strlen(str) - 1;
    char c;

    strcpy(my_string, str);
    while (i < j) {
        c = str[i];
        my_string[i] = my_string[j];
        my_string[j] = c;
        i = i + 1;
        j = j - 1;
    }
    printf("%s\n", my_string);
}

void print_upper(const char *str)
{
    int i = 0;
    char *my_string = malloc(sizeof(char) * strlen(str));

    strcpy(my_string, str);
    while (my_string[i] != '\0') {
        printf("%c", toupper(my_string[i]));
        i++;
    }
    printf("\n");
}

void print_42(const char *str)
{
    str = str;
    printf("42\n");
}

void do_action(action_t action, const char *str)
{
    void (*fct[4])(const char *) = {print_normal, print_reverse,
				    print_upper, print_42};
    (*fct[action])(str);
}
