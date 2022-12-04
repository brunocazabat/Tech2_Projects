/*
** EPITECH PROJECT, 2019
** fruitnode
** File description:
** fruitnode
*/

#ifndef FRUITNODE_HPP_
#define FRUITNODE_HPP_

#include "Fruit.hpp"

typedef struct FruitNode {
    Fruit *fruit;
    FruitNode *next;
} FruitNode;

#endif /* !FRUITNODE_HPP_ */
