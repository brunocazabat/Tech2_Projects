/*
** EPITECH PROJECT, 2019
** hand
** File description:
** hand
*/

#include "LittleHand.hpp"

void LittleHand::sortFruitBox(FruitBox &unsorted, FruitBox &lemons, FruitBox &bananas, FruitBox &limes)
{
    FruitNode *tmp = unsorted.head();

    while (tmp->next != NULL) {
        if (tmp->fruit->getName() == "lemon" && lemons.putFruit(tmp->fruit))
            unsorted.pickFruit();
        else if (tmp->fruit->getName() == "banana" && bananas.putFruit(tmp->fruit))
            unsorted.pickFruit();
        else if (tmp->fruit->getName() == "lime" && limes.putFruit(tmp->fruit))
            unsorted.pickFruit();
        tmp = tmp->next;
    }
}
