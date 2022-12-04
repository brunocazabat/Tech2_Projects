/*
** EPITECH PROJECT, 2019
** warrior
** File description:
** warrior
*/

#include "Warrior.hpp"

Warrior::Warrior(const std::string &name, int level, const std::string &weapon) : Character(name, level)
{
    _stamina = 12;
    _spirit = 5;
    _agility = 7;
    _intelligence = 6;
    _strength = 12;
    _class = "Warrior";
    _race = "Dwarf";
    weaponName = weapon;
    std::cout << "I'm " << _name << " KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG" << std::endl;
}

Warrior::~Warrior()
{
}

int Warrior::CloseAttack()
{
    if (_energy < 30) {
        std::cout << _name << " out of power" << std::endl;
        return (0);
    } else {
        _energy -= 30;
        std::cout << _name << " strikes with his " << weaponName << std::endl;
        return (20 + _strength);
    }
}

int Warrior::RangeAttack()
{
    if (_energy < 10) {
        std::cout << _name << " out of power" << std::endl;
        return (0);
    } else {
        _energy -= 10;
        std::cout << _name << " intercepts" << std::endl;
        Range = CLOSE;
        return (0);
    }
}