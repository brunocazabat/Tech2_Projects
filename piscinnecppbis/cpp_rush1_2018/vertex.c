/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 02
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vertex.h"
#include "new.h"

typedef struct
{
    Class   base;
    int     x, y, z;
}   VertexClass;

static void Vertex_ctor(VertexClass *this, va_list *args)
{
    if (!this)
        raise("error in Vertex_ctor");
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
    this->z = va_arg(*args, int);
}

static void Vertex_dtor(VertexClass *this)
{
    if (!this)
        raise("error in Vertex_dtor");
    free(this);
}

char const *Vertex_str(VertexClass *this)
{
    char *str = malloc(sizeof(Vertex->__size__));

    if (!str || !this)
        raise("malloc error in Vertex_str");
    sprintf(str, "<%s (%d, %d, %d)>", Vertex->__name__, this->x, this->y, this->z);
    return (str);
}

Object *Vertex_add(const VertexClass *this, const VertexClass *other)
{
    int x = 0;
    int y = 0;
    int z = 0;
    Object  *that = NULL;

    if (!this || !other)
        raise("error in Vertex_add");
    x = this->x + other->x;
    y = this->y + other->y;
    z = this->z + other->z;
    new(Vertex, x, y, z);
    return (that);
}

Object *Vertex_sub(const VertexClass *this, const VertexClass *other)
{
    int x = 0;
    int y = 0;
    int z = 0;
    Object  *that = NULL;

    if (!this || !other)
        raise("error in Vertex_add");
    x = this->x - other->x;
    y = this->y - other->y;
    z = this->z - other->z;
    new(Vertex, x, y, z);
    return (that);
}

static VertexClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(VertexClass),
        .__name__ = "Vertex",
        .__ctor__ = (ctor_t)&Vertex_ctor,
        .__dtor__ = (dtor_t)&Vertex_dtor,
        .__str__ = (to_string_t)&Vertex_str,    /* Implement this method for exercice 02 */
        .__add__ = (binary_operator_t)&Vertex_add,    /* Implement this method for exercice 03 */
        .__sub__ = (binary_operator_t)&Vertex_sub,    /* Implement this method for exercice 03 */
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0,
    .z = 0
};

Class   *Vertex = (Class *)&_description;
