/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/

#include "Paladin.hpp"

Paladin::Paladin(std::string const &name, int lvl) : Character(name, lvl), Warrior(name, lvl), Priest(name, lvl)
{
    this->_Strength = 9;
    this->_Stamina = 10;
    this->_Intelligence = 10;
    this->_Spirit = 10;
    this->_Agility = 2;
    std::cout << "the light falls on " << _Name << std::endl;
}

Paladin::~Paladin()
{
}

int	Paladin::Intercept()
{
    return Warrior::RangeAttack();
}