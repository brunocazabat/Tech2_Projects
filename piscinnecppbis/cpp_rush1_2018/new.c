/*
** EPITECH PROJECT, 2019
** new
** File description:
** new
*/
#include "new.h"
#include "player.h"
#include "object.h"
#include "string.h"
#include "point.h"
#include "raise.h"

Object  *new(Class *class, ...)
{
    Object *p;
    va_list arg;

    va_start(arg, class);
    p = va_new(class, &arg);
    va_end(arg);
    return (p);
}

Object  *va_new(Class *class, va_list* ap)
{
    Object *p = calloc(1, class->__size__);

    if (!p)
        raise("malloc error in va_new");
    memcpy(p, class, class->__size__);
    if (class->__ctor__)
            class->__ctor__(p, ap);
    return (p);
}

void    delete(Object *ptr)
{
    Class *obj = ptr;
    
    if (obj->__dtor__)
        obj->__dtor__(ptr);
}