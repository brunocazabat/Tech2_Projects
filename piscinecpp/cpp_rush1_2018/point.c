/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 02
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "point.h"
#include "new.h"
#include "raise.h"

typedef struct
{
    Class   base;
    int     x, y;
}   PointClass;

static void Point_ctor(PointClass *this, va_list *args)
{
    if (!this)
        raise("error in Point_ctor");
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
}

static void Point_dtor(PointClass *this)
{
    if (!this)
        raise("error in Point_dtor");    
    free(this);
}

char const *Point_str(PointClass *this)
{
    char *str = malloc(sizeof(Point->__size__));

    if (!str || !this)
        raise("malloc error in Point_str");
    sprintf(str, "<%s (%d, %d)>", Point->__name__, this->x, this->y);
    return (str);
}

Object *Point_add(const PointClass *this, const PointClass *other)
{
    int x = 0;
    int y = 0;
    Object  *that = NULL;

    if (!this || !other)
        raise("error in Point_add");
    x = this->x + other->x;
    y = this->y + other->y;
    that = new(Point, x, y);
    return (that);
}

Object *Point_sub(const PointClass *this, const PointClass *other)
{
    int x = 0;
    int y = 0;
    Object  *that = NULL;

    if (!this || !other)
        raise("error in Point_sub");
    x = this->x - other->x;
    y = this->y - other->y;
    that = new(Point, x, y);
    return (that);
}

static PointClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(PointClass),
        .__name__ = "Point",
        .__ctor__ = (ctor_t)&Point_ctor,
        .__dtor__ = (dtor_t)&Point_dtor,
        .__str__ = (to_string_t)&Point_str,    /* Implement this method for exercice 02 */
        .__add__ = (binary_operator_t)&Point_add,    /* Implement this method for exercice 03 */
        .__sub__ = (binary_operator_t)&Point_sub,    /* Implement this method for exercice 03 */
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0
};

Class   *Point = (Class *)&_description;
