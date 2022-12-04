/*
** EPITECH PROJECT, 2019
** hunter
** File description:
** hunter
*/

#include "Hunter.hpp"

Hunter::Hunter(const std::string &name, int level) : Character(name, level), Warrior(name, level, "sword")
{
    _stamina = 9;
    _spirit = 6;
    _agility = 25;
    _intelligence = 5;
    _strength = 9;
    _class = "Hunter";
    _race = "Elf";
    std::cout << _name << " is born from a tree" << std::endl;
}

Hunter::~Hunter()
{
}

void Hunter::RestorePower()
{
    _energy = 100;
    std::cout << _name << " meditates" << std::endl;
}

int Hunter::RangeAttack()
{
    if (_energy < 25) {
        std::cout << _name << " out of power" << std::endl;
        return (0);
    } else {
        _energy -= 25;
        std::cout << _name << " uses his bow" << std::endl;
        Range = CLOSE;
        return (20 + _agility);
    }
}

