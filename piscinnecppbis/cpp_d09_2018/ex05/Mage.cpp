/*
** EPITECH PROJECT, 2019
** mage
** File description:
** mage
*/

#include "Mage.hpp"

Mage::Mage(const std::string &name, int level) : Character(name, level)
{
    _stamina = 6;
    _spirit = 11;
    _agility = 7;
    _intelligence = 12;
    _strength = 6;
    _class = "Mage";
    _race = "Gnome";
    std::cout << _name << " teleported" << std::endl;
}

Mage::~Mage()
{
}

int Mage::CloseAttack()
{
    if (_energy < 10) {
        std::cout << _name << " out of power" << std::endl;
        return (0);
    } else {
        _energy -= 10;
        std::cout << _name << " blinks" << std::endl;
        Range = RANGE;
        return (0);
    }
}

int Mage::RangeAttack()
{
    if (_energy < 25) {
        std::cout << _name << " out of power" << std::endl;
        return (0);
    } else {
        _energy -= 25;
        std::cout << _name << " launches a fire ball" << std::endl;
        return (20 + _spirit);
    }
}

void Mage::RestorePower()
{
    if (_energy + 50 + _intelligence > 100)
        _energy = 100;
    else
        _energy += 50 + _intelligence;
    std::cout << _name << " takes a mana potion" << std::endl;
}
