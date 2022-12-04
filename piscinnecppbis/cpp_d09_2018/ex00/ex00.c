/*
** EPITECH PROJECT, 2019
** 00
** File description:
** 00
*/

#include "ex00.h"

static void koala_initializer(koala_t *this, char *_name, char _is_A_Legend)
{
    cthulhu_t *cthulhu = new_cthulhu();

    cthulhu->m_power = 42;
    this->m_parent.m_name = strdup(_name);
    this->m_is_a_legend = _is_A_Legend;
    this->m_parent.m_power = (this->m_is_a_legend == 1) ? 42 : 0;
    printf("Building %s\n", this->m_parent.m_name);
}

static void cthulhu_initializer(cthulhu_t *this)
{
    this->m_name = "Cthulhu";
    this->m_power = 42;
    printf("----\n");
    printf("Building %s\n", this->m_name);
}

cthulhu_t *new_cthulhu()
{
    cthulhu_t *this = malloc(sizeof(cthulhu_t));

    cthulhu_initializer(this);
    return (this);
}

void print_power(cthulhu_t *this)
{
    printf("Power => %d\n", this->m_power);
}

void attack(cthulhu_t *this)
{
    if (this->m_power >= 42) {
        this->m_power -= 42;
        printf("%s attacks and destroys the city\n", this->m_name);
    } else
        printf("%s can't attack, he doesn't have enough power\n", this->m_name);
}

void sleeping(cthulhu_t *this)
{
    printf("%s sleeps\n", this->m_name);
    this->m_power += 42000;
}

koala_t *new_koala(char *name, char is_a_legend)
{
    koala_t *this = malloc(sizeof(koala_t));

    koala_initializer(this, name, is_a_legend);
    return (this);
}

void eat(koala_t *this)
{
    printf("%s eats\n", this->m_parent.m_name);
    this->m_parent.m_power += 42;
}