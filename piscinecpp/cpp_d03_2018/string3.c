/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/
#include "string.h"

int size(const string_t *this)
{
    int i = 0;
	
    i = strlen(this->str);
    return (i);
}

int compare_s(const string_t *this, const string_t *str)
{
    if (str->str == NULL || this->str == NULL)
        return (0);
    return (strcmp(str->str, this->str));
}

int compare_c(const string_t *this, const char *str)
{
    if ( str == NULL || this->str == NULL)
        return (0);
    return (strcmp(str, this->str));
}
