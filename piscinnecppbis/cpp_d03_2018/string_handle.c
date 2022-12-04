/*
** EPITECH PROJECT, 2019
** test
** File description:
** test
*/

#include "string.h"

void string_destroy(string_t *this)
{
    if (this)
        free(this->str);
}

int compare_s(const string_t *this, const string_t *str)
{
    return (strcmp(this->str, str->str));
}

int compare_c(const string_t *this, const char *str)
{
    return (strcmp(this->str, str));
}

size_t copy(const string_t *this, char *s, size_t n, size_t pos)
{
    int i = 0;

    if (!this || !s || n + pos < strlen(this->str) - 1 || pos > strlen(this->str) - 1)
        return (0);
    while (this->str[pos] != '\0') {
        s[i] = this->str[pos];
        i++;
        pos++;
    }
    return ((i == 0) ? 0 : i);
}

void string_init(string_t *this, const char *s)
{
    if (this && s)
        this->str = strdup(s);
    this->assign_s = assign_s;
    this->assign_c = assign_c;
    this->append_s = append_s;
    this->append_c = append_c;
    this->at = at;
    this->size = size;
    this->compare_s = compare_s;
    this->compare_c = compare_c;
    this->copy = copy;
    this->c_str = c_str;
    this->empty = empty;
    this->clear = clear;
}