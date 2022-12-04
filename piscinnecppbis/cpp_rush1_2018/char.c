/*
** EPITECH PROJECT, 2019
** char.c
** File description:
** char.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "char.h"
#include "new.h"
#include "raise.h"

typedef struct
{
    Class   base;
    char     c;
}   CharClass;

static void Char_ctor(CharClass *this, va_list *args)
{
    if (!this)
        raise("error in Char_ctor");
    this->c = va_arg(*args, int);
}

static void Char_dtor(CharClass *this)
{
    if (!this)
        raise("error in Char_dtor");
    free(this);
}

char const *Char_str(CharClass *this)
{
    char *str = malloc(sizeof(Char->__size__));
    
    if (!str || !this)
        raise("malloc error in Char_str");
    sprintf(str, "<%s (%c)>", Char->__name__, this->c);
    return (str);
}

Object *Char_add(const CharClass *this, const CharClass *other)
{
    char c = '\0';
    Object  *that = NULL;

    if (!this || !other)
        raise("error in Char_add");
    c= this->c + other->c;
    that = new(Char, c);
    return (that);
}

Object *Char_sub(const CharClass *this, const CharClass *other)
{
    char c = '\0';
    Object  *that = NULL;

    if (!this || !other)
        raise("error in Char_sub");
    c= this->c - other->c;
    that = new(Char, c);
    return (that);
}

Object *Char_mul(const CharClass *this, const CharClass *other)
{
    char c = '\0';
    Object  *that = NULL;

    if (!this || !other)
        raise("error in Char_mul");
    c= this->c * other->c;
    that = new(Char, c);
    return (that);
}

Object *Char_div(const CharClass *this, const CharClass *other)
{
    char c = '\0';
    Object  *that = NULL;

    if (!this || !other || other->c != '\0')
        raise("error in Char_div");
    c= this->c / other->c;
    that = new(Char, c);
    return (that);
}

bool Char_eq(const CharClass *this, const CharClass *other)
{
    if (!this || !other)
        raise("error in Char_eq");
    if (this->c == other->c)
        return (true);
    return (false);
}

bool Char_gt(const CharClass *this, const CharClass *other)
{
    if (!this || !other)
        raise("error in Char_gt");
    if (this->c > other->c)
        return (true);
    return (false);
}

bool Char_lt(const CharClass *this, const CharClass *other)
{
    if (!this || !other)
        raise("error in Char_lt");
    if (this->c < other->c)
        return (true);
    return (false);
}

static CharClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(CharClass),
        .__name__ = "Char",
        .__ctor__ = (ctor_t)&Char_ctor,
        .__dtor__ = (dtor_t)&Char_dtor,
        .__str__ = (to_string_t)&Char_str,    /* Implement this method for exercice 02 */
        .__add__ = (binary_operator_t)&Char_add,    /* Implement this method for exercice 03 */
        .__sub__ = (binary_operator_t)&Char_sub,    /* Implement this method for exercice 03 */
        .__mul__ = (binary_operator_t)&Char_mul,
        .__div__ = (binary_operator_t)&Char_div,
        .__eq__ = (binary_comparator_t)&Char_eq,
        .__gt__ = (binary_comparator_t)&Char_gt,
        .__lt__ = (binary_comparator_t)&Char_lt
    },
    .c = 0
};

Class   *Char = (Class *)&_description;