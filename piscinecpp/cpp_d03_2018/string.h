/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/

#ifndef STRINGLOL_H_
#define STRINGLOL_H_

typedef struct string_s string_t;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void string_init(string_t *this, const char *s);
void string_destroy(string_t *this);
void assign_s(string_t *this, const string_t *str);
void assign_c(string_t *this, const char *s);
void append_s(string_t *this, const string_t *ap);
void append_c(string_t *this, const char *ap);
void clear(string_t *this);
char at(const string_t *this, size_t pos);
int size(const string_t *this);
int compare_s(const string_t *this, const string_t *str);
int compare_c(const string_t *this, const char *str);

int strcmp(const char *s1, const char *s2);
char *strdup(const char *s);
char *strcat(char *dest, const char *src);
size_t strlen(const char *s);

struct string_s
{
    char *str;
    void (*string_init)(string_t *this, const char *s);
    void (*string_destroy)(string_t *this);
    void (*assign_s)(string_t *this, const string_t *str);
    void (*assign_c)(string_t *this, const char *s);
    void (*append_s)(string_t *this, const string_t *ap);
    void (*append_c)(string_t *this, const char *ap);
    void (*clear)(string_t *this);
    char (*at)(const string_t *this, size_t pos);
    int (*size)(const string_t *this);
    int (*compare_s)(const string_t *this, const string_t *str);
    int (*compare_c)(const string_t *this, const char *str);
};

#endif
