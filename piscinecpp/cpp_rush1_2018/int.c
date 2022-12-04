/*
** EPITECH PROJECT, 2019
** int.c
** File description:
** int.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "int.h"
#include <string.h>
#include "new.h"

typedef struct
{
    Class   base;
    int     x;
}   IntClass;

static void Int_ctor(IntClass *this, va_list *args)
{
    if (!this)
        raise("error in Int_ctor");
    this->x = va_arg(*args, int);
}

static void Int_dtor(IntClass *this)
{
    if (!this)
        raise("error in Int_dtor");
    free(this);
}

char const *Int_str(IntClass *this)
{
    char *str = malloc(sizeof(Int->__size__));

    if (!str || !this)
        raise("malloc error in Int_str");
    sprintf(str, "<%s (%d)>", Int->__name__, this->x);
    return (str);
}

Object *Int_add(const IntClass *this, const IntClass *other)
{
    int x = 0;
    
    if (!this || !other)
        raise("error in Int_add");
    x = this->x + other->x;
    Object  *that = new(Int, x);
    return (that);
}

Object *Int_sub(const IntClass *this, const IntClass *other)
{
    int x = 0;
    
    if (!this || !other)
        raise("error in Int_sub");
    x = this->x - other->x;
    Object  *that = new(Int, x);
    return (that);
}

Object *Int_mul(const IntClass *this, const IntClass *other)
{
    int x = 0;
    
    if (!this || !other)
        raise("error in Int_mul");
    x = this->x * other->x;
    Object  *that = new(Int, x);
    return (that);
}

Object *Int_div(const IntClass *this, const IntClass *other)
{
    int x = 0;
    
    if (!this || !other || other->x != 0)
        raise("error in Int_div");
    x = this->x / other->x;
    Object  *that = new(Int, x);
    return (that);
}

bool Int_eq(const IntClass *this, const IntClass *other)
{
    if (!this || !other)
        raise("error in Int_eq");
    if (this->x == other->x)
        return (true);
    return (false);
}

bool Int_gt(const IntClass *this, const IntClass *other)
{
    if (!this || !other)
        raise("error in Int_gt");
    if (this->x > other->x)
        return (true);
    return (false);
}

bool Int_lt(const IntClass *this, const IntClass *other)
{
    if (!this || !other)
        raise("error in Int_lt");
    if (this->x < other->x)
        return (true);
    return (false);
}

static IntClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(IntClass),
        .__name__ = "Int",
        .__ctor__ = (ctor_t)&Int_ctor,
        .__dtor__ = (dtor_t)&Int_dtor,
        .__str__ = (to_string_t)&Int_str,    /* Implement this method for exercice 02 */
        .__add__ = (binary_operator_t)&Int_add,    /* Implement this method for exercice 03 */
        .__sub__ = (binary_operator_t)&Int_sub,    /* Implement this method for exercice 03 */
        .__mul__ = (binary_operator_t)&Int_mul,
        .__div__ = (binary_operator_t)&Int_div,
        .__eq__ = (binary_comparator_t)&Int_eq,
        .__gt__ = (binary_comparator_t)&Int_gt,
        .__lt__ = (binary_comparator_t)&Int_lt
    },
    .x = 0
};

Class   *Int = (Class *)&_description;
