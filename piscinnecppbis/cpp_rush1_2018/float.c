/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 02
*/

#include <stdio.h>
#include <stdlib.h>
#include "float.h"
#include <string.h>
#include "new.h"

typedef struct
{
    Class   base;
    float     x;
}   FloatClass;

static void Float_ctor(FloatClass *this, va_list *args)
{
    if (!this)
        raise("error in Float_ctor");
    this->x = va_arg(*args, double);
}

static void Float_dtor(FloatClass *this)
{
    if (!this)
        raise("error in Float_dtor");
    free(this);    
}

char const *Float_str(FloatClass *this)
{

    char *str = malloc(sizeof(Float->__size__));

    if (!str || !this)
        raise("malloc error in Float_str");
    sprintf(str, "<%s (%f)>", Float->__name__, this->x);
    return (str);
}

Object *Float_add(const FloatClass *this, const FloatClass *other)
{
    float x = 0.0;

    if (!this || !other)
        raise("error in Float_add");
    x = this->x + other->x;
    Object  *that = new(Float, x);
    return (that);
}

Object *Float_sub(const FloatClass *this, const FloatClass *other)
{
    float x = 0.0;

    if (!this || !other)
        raise("error in Float_sub");
    x = this->x - other->x;
    Object *that = new(Float, x);
    return (that);
}

Object *Float_mul(const FloatClass *this, const FloatClass *other)
{
    float x = 0.0;

    if (!this || !other)
        raise("error in Float_mul");
    x = this->x * other->x;
    Object  *that = new(Float, x);
    return (that);
}

Object *Float_div(const FloatClass *this, const FloatClass *other)
{
    float x = 0.0;

    if (!this || !other || other->x != 0)
        raise("error in Float_div");
    x = this->x / other->x;
    Object  *that = new(Float, x);
    return (that);
}
bool Float_eq(const FloatClass *this, const FloatClass *other)
{
    if (!this || !other)
        raise("error in Float_eq");
    if (this->x == other->x)
        return (true);
    return (false);
}

bool Float_gt(const FloatClass *this, const FloatClass *other)
{
    if (!this || !other)
        raise("error in Float_gt");
    if (this->x > other->x)
        return (true);
    return (false);
}

bool Float_lt(const FloatClass *this, const FloatClass *other)
{
    if (!this || !other)
        raise("error in Float_lt");
    if (this->x < other->x)
        return (true);
    return (false);
}

static FloatClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(FloatClass),
        .__name__ = "Float",
        .__ctor__ = (ctor_t)&Float_ctor,
        .__dtor__ = (dtor_t)&Float_dtor,
        .__str__ = (to_string_t)&Float_str,    /* Implement this method for exercice 02 */
        .__add__ = (binary_operator_t)&Float_add,    /* Implement this method for exercice 03 */
        .__sub__ = (binary_operator_t)&Float_sub,    /* Implement this method for exercice 03 */
        .__mul__ = (binary_operator_t)&Float_mul,
        .__div__ = (binary_operator_t)&Float_div,
        .__eq__ = (binary_comparator_t)&Float_eq,
        .__gt__ = (binary_comparator_t)&Float_gt,
        .__lt__ = (binary_comparator_t)&Float_lt,
    },
    .x = 0.0,
};

Class   *Float = (Class *)&_description;
