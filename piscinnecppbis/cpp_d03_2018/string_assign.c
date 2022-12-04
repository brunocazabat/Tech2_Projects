/*
** EPITECH PROJECT, 2019
** assign
** File description:
** assign
*/

#include "string.h"

void append_s(string_t *this, const string_t *ap)
{
    char *tmp = NULL;

    if (this && ap) {
        tmp = strdup(this->str);
        free(this->str);
        this->str = malloc(sizeof(char) * (this->size(ap) + strlen(tmp)));
        strcat(this->str, tmp);
        strcat(this->str, ap->str);
        free(tmp);
    }
}

void append_c(string_t *this, const char *ap)
{
    char *tmp = NULL;

    if (this && ap) {
        tmp = strdup(this->str);
        free(this->str);
        this->str = malloc(sizeof(char) * (strlen(ap) + strlen(tmp)));
        strcat(this->str, tmp);
        strcat(this->str, ap);
        free(tmp);
    }
}

void assign_s(string_t *this, const string_t *str)
{
    if (str && this) {
        free(this->str);
        this->str = strdup(str->str);
    }
}

void assign_c(string_t *this, const char *s)
{
    if (s && this) {
        free(this->str);
        this->str = strdup(s);
    }
}