/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/
#include "string.h"

void append_s(string_t *this, const string_t *ap)
{
    this->str = strcat(this->str, ap->str);
}

void append_c(string_t *this, const char *ap)
{
    this->str = strcat(this->str, ap);
}

void clear(string_t *this)
{
    this->str = NULL;
}

char at(const string_t *this, size_t pos)
{
    if (pos < 0 || this->str == NULL || pos >= strlen(this->str))
        return (-1);
    return (this->str[pos]);
}
