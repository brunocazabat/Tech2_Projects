/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/
#include "ex00.h"

static void koala_initializer(koala_t *this, char *_name, char _is_A_Legend)
{
    cthulhu_t   *thisnew;

    thisnew = new_cthulhu();
    this->m_parent = *thisnew;
    this->m_parent.m_name = strdup(_name);
    if (_is_A_Legend < 1)
        this->m_parent.m_power = 0;
    this->m_is_a_legend = _is_A_Legend;
}

cthulhu_t 	*new_cthulhu()
{
    cthulhu_t   *thisnew;
    if ((thisnew = malloc(sizeof(cthulhu_t))) == NULL)
        return (NULL);
    cthulhu_initializer(thisnew);
    printf("----\nBuilding %s\n", thisnew->m_name);
    return (thisnew);
}

static void cthulhu_initializer(cthulhu_t *this)
{
    if ((this->m_name = malloc(sizeof(char) * strlen("Cthulhu"))) == NULL)
        return;
    this->m_name = "Cthulhu";
    this->m_power = 42;
}

void    eat(koala_t *this)
{
    this->m_parent.m_power = 42;
    printf("%s eats\n", this->m_parent.m_name);
}

void    print_power(cthulhu_t *this)
{
    printf("Power => %d\n", this->m_power);
}

void    attack(cthulhu_t *this)
{
    if (this->m_power >= 42)
    {
        this->m_power = this->m_power - 42;
        printf("%s attacks and destroys the city\n", this->m_name);
    }
    else
        printf("%s can't attack, he doesn't have enough power\n", this->m_name);
}

void    sleeping(cthulhu_t *this)
{
    this->m_power = 42000;
    printf("%s sleeps\n", this->m_name);
}

koala_t     *new_koala(char *name, char is_a_legend)
{
    koala_t     *this;

    if ((this = malloc(sizeof(koala_t))) == NULL)
        return (NULL);
    koala_initializer(this, name, is_a_legend);
    printf("Building %s\n", this->m_parent.m_name);
    return (this);
}