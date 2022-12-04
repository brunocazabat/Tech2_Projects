/*
** EPITECH PROJECT, 2019
** info
** File description:
** info
*/

#include "string.h"

int size(const string_t *this)
{
    if (this && this->str != NULL)
        return (strlen(this->str));
    return (-1);
}

int empty(const string_t *this)
{
    return ((this->str == NULL || !this->str[0]) ? 1 : 0);
}

const char *c_str(const string_t *this)
{
    if (!this)
        return (NULL);
    return (this->str);
}

void clear(string_t *this)
{
    if (this)
        memset(this->str, '\0', strlen(this->str));
}

char at(const string_t *this, size_t pos)
{
    if (pos > strlen(this->str) - 1)
        return (-1);
    return (this->str[pos]);
}