/*
** EPITECH PROJECT, 2019
** priest
** File description:
** priest
*/

#include "Priest.hpp"

Priest::Priest(const std::string &name, int level) : Mage(name, level)
{
    _stamina = 4;
    _spirit = 21;
    _agility = 2;
    _intelligence = 42;
    _strength = 4;
    _class = "Priest";
    _race = "Orc";
    std::cout << _name << " enters in the order" << std::endl;
}

Priest::~Priest()
{
}

int Priest::CloseAttack()
{
    if (_energy < 10) {
        std::cout << _name << " out of power" << std::endl;
        return (0);
    } else {
        _energy -= 10;
        std::cout << _name << " uses a spirit explosion" << std::endl;
        Range = RANGE;
        return (10 + _spirit);
    }
}

void Priest::Heal()
{
    if (_energy >= 10) {
        if (_pv + 70 > 100)
            _pv = 100;
        else
            _pv += 70;
        _energy -= 10;
        std::cout << _name << " casts a little heal spell" << std::endl;
    } else
        std::cout << _name << " out of power" << std::endl;
}