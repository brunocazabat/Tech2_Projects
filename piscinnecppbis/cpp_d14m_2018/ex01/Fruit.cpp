/*
** EPITECH PROJECT, 2019
** fruit
** File description:
** fruit
*/

#include "Fruit.hpp"

Fruit::Fruit(const int vitamins, const std::string &name)
{
    _vitamins = vitamins;
    _name = name;
}

Fruit::~Fruit()
{
}

int Fruit::getVitamins() const
{
    return (_vitamins);
}

std::string Fruit::getName() const
{
    return (_name);
}