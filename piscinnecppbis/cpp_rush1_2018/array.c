/*
** EPITECH PROJECT, 2019
** cpp_rush1
** File description:
** Exercice 05
*/

#include <stdlib.h>
#include <stdarg.h>
#include "raise.h"
#include "array.h"
#include "new.h"
#include <string.h>

typedef struct
{
    Container   base;
    Class       *_type;
    size_t      _size;
    Object      **_tab;
}   ArrayClass;

typedef struct {
    Iterator    base;
    ArrayClass  *_array;
    size_t      _idx;
}   ArrayIteratorClass;

static void     ArrayIterator_ctor(ArrayIteratorClass *this, va_list *args)
{
    this->_array = va_arg(*args, ArrayClass *);
    this->_idx = va_arg(*args, int);
}

static bool     ArrayIterator_eq(ArrayIteratorClass *this, ArrayIteratorClass *other)
{
    return (this->_idx == other->_idx);
}

static bool     ArrayIterator_gt(ArrayIteratorClass *this, ArrayIteratorClass *other)
{
    return (this->_idx > other->_idx);
}

static bool     ArrayIterator_lt(ArrayIteratorClass *this, ArrayIteratorClass *other)
{
    return (this->_idx < other->_idx);
}

static void     ArrayIterator_incr(ArrayIteratorClass *this)
{
    this->_idx += 1;
}

static Object   *ArrayIterator_getval(ArrayIteratorClass *this)
{
    if (!this || this->_idx >= this->_array->_size)
        raise("Out of range");
    return (this->_array->_tab[this->_idx]);
}

static void     ArrayIterator_setval(ArrayIteratorClass *this, ...)
{
    Object *new;
    va_list arg;

    if (!this)
        raise("Error in Array_Iterator_setbal");
    va_start(arg, this);
    new = va_new(this->_array->_type, &arg);
    if (this->_idx >= this->_array->_size)
        raise("Error in Array_Iterator_setbal");
    delete(this->_array->_tab[this->_idx]);
    this->_array->_tab[this->_idx] = new;
    va_end(arg);
}

static ArrayIteratorClass   ArrayIteratorDescr = {
    {   /* Iterator struct */
        {   /* Class struct */
            .__size__ = sizeof(ArrayIteratorClass),
            .__name__ = "ArrayIterator",
            .__ctor__ = (ctor_t)&ArrayIterator_ctor,
            .__dtor__ = NULL,
            .__str__ = NULL,
            .__add__ = NULL,
            .__sub__ = NULL,
            .__mul__ = NULL,
            .__div__ = NULL,
            .__eq__ = (binary_comparator_t)&ArrayIterator_eq,
            .__gt__ = (binary_comparator_t)&ArrayIterator_gt,
            .__lt__ = (binary_comparator_t)&ArrayIterator_lt,
        },
        .__incr__ = (incr_t)&ArrayIterator_incr,
        .__getval__ = (getval_t)&ArrayIterator_getval,
        .__setval__ = (setval_t)&ArrayIterator_setval,
    },
    ._array = NULL,
    ._idx = 0
};

static Class    *ArrayIterator = (Class *)&ArrayIteratorDescr;

static void     Array_ctor(ArrayClass *this, va_list *args)
{
    int i = 0;
    va_list elem;

    this->_size = va_arg(*args, size_t);
    this->_type = va_arg(*args, Class *);
    this->_tab = NULL;
    this->_tab = malloc(sizeof(Object *) * this->_size);
    if (!this->_tab || this->_size == 0)
        raise("error Array_ctor");
    for (i = 0; i < this->_size; i++) {
        va_copy(elem, *args);
        this->_tab[i] = va_new(this->_type, &elem);
        va_end(elem);
    }
}

static void     Array_dtor(ArrayClass *this)
{
    for (unsigned int i = 0; i < this->_size; i++)
        delete(this->_tab[i]);
    free(this->_tab);
}

static size_t   Array_len(ArrayClass *this)
{
    return (this->_size);
}

static Iterator *Array_begin(ArrayClass *this)
{
    return (new(ArrayIterator, this, 0));
}

static Iterator *Array_end(ArrayClass *this)
{
    return (new(ArrayIterator, this, this->_size));
}

static Object   *Array_getitem(ArrayClass *this, ...)
{
    va_list arg;
    size_t i = 0;

    if (!this)
        raise("Error in Array_getItem");
    va_start(arg, this);
    i = va_arg(arg, size_t);
    if (i >= this->_size)
        raise("Error in Array_getItem");
    va_end(arg);
    return (this->_tab[i]);
}

static void     Array_setitem(ArrayClass *this, ...)
{
    Object *new;
    va_list arg;
    size_t i = 0;

    if (!this)
        raise("Error in Array_setItem");
    va_start(arg, this);
    i = va_arg(arg, size_t);
    new = va_new(this->_type, &arg);
    if (i >= this->_size)
        raise("Error in Array_setItem");
    delete(this->_tab[i]);
    this->_tab[i] = new;
    va_end(arg);
}

static ArrayClass   _descr = {
    {   /* Container struct */
        {   /* Class struct */
            .__size__ = sizeof(ArrayClass),
            .__name__ = "Array",
            .__ctor__ = (ctor_t)&Array_ctor,
            .__dtor__ = (dtor_t)&Array_dtor,
            .__str__ = NULL,
            .__add__ = NULL,
            .__sub__ = NULL,
            .__mul__ = NULL,
            .__div__ = NULL,
            .__eq__ = NULL,
            .__gt__ = NULL,
            .__lt__ = NULL,
        },
        .__len__ = (len_t)&Array_len,
        .__begin__ = (iter_t)&Array_begin,
        .__end__ = (iter_t)&Array_end,
        .__getitem__ = (getitem_t)&Array_getitem,
        .__setitem__ = (setitem_t)&Array_setitem,
    },
    ._type = NULL,
    ._size = 0,
    ._tab = NULL
};

Class   *Array = (Class *)&_descr;
