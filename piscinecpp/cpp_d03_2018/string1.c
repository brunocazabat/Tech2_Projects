/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/
#include "string.h"

void string_init(string_t *this, const char *s)
{
    int i = 0;

    while (s[i])
        i = i + 1;
    this->str = malloc(sizeof(char) * i + 1);
    i = 0;
    while (s[i]) {
	this->str[i] = s[i];
	i = i + 1;
    }
    this->str[i] = '\0';
}

void string_destroy(string_t *this)
{
    free(this->str);
}

void assign_s(string_t *this, const string_t *str)
{
    if (this && str) {
        free(this->str);
        this->str = strdup(str->str);
    }
}

void assign_c(string_t *this, const char *s)
{
    if (this && s) {
        free(this->str);
        this->str = strdup(s);
    }
}
