/*
** EPITECH PROJECT, 2019
** mayet/cazabat
** File description:
** malloc
*/

#include "malloc.h"

int system(const char *commande)
{
    (void*)commande;
    return (0);
}

void *malloc(size_t size)
{
    return (sbrk(size));
}

void *free(void *p)
{
    brk(p);
}

void *realloc(void *p, size_t size)
{
    p = malloc(size);
}
