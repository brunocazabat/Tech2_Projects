/*
** EPITECH PROJECT, 2019
** pala
** File description:
** pala
*/

#include "Paladin.hpp"

Paladin::Paladin(const std::string &name, int level) : Character(name, level), Warrior(name, level), Priest(name, level)
{
    _stamina = 10;
    _spirit = 10;
    _agility = 2;
    _intelligence = 10;
    _strength = 9;
    _class = "Paladin";
    _race = "Human";
    std::cout << "the light falls on " << _name << std::endl;
}

Paladin::~Paladin()
{
}

int Paladin::Intercept()
{
    return (Warrior::RangeAttack());
}