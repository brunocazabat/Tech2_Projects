/*
** EPITECH PROJECT, 2019
** fruitbox
** File description:
** fruitbox
*/

#include "FruitBox.hpp"

FruitBox::FruitBox(const int size)
{
    _size = size;
    _nbFruits = 0;
    _head = NULL;
}

FruitBox::~FruitBox()
{
}

int FruitBox::nbFruits() const
{
    return (_nbFruits);
}

bool FruitBox::putFruit(Fruit *f)
{
    FruitNode *tmp = _head;
    FruitNode *node = new FruitNode;

    if (_nbFruits == _size)
        return (false);
    node->fruit = f;
    if (_head == NULL) {
        _head = node;
        node->next = NULL;
        _nbFruits += 1;
        return (true);
    }    
    while (tmp->next != NULL) {
        if (tmp->fruit == f)
            return (false);
        tmp = tmp->next;
    }
    if (tmp->fruit == f)
        return (false);
    tmp->next = node;
    node->next = NULL;
    _nbFruits += 1;
    return (true);
}

Fruit *FruitBox::pickFruit()
{
    Fruit *fruit = (_head == NULL) ? NULL : _head->fruit;
    if (_head != NULL) {
        _head = _head->next;
        _nbFruits -= 1;
    }
    return (fruit);
}

FruitNode *FruitBox::head()
{
    return (_head);
}

FruitBox::FruitBox(const FruitBox &box)
{
    (void)box;
}

FruitBox &FruitBox::operator=(const FruitBox &box)
{
    (void)box;
    return (*this);
}
