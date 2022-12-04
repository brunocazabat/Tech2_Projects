/*
** EPITECH PROJECT, 2019
** Charac
** File description:
** Charac
*/

#include "Character.hpp"

Character::~Character()
{

}

Character::Character(const std::string &name, int level)
{
    _name = name;
    _level = level;
    _pv = 100;
    _energy = 100;
    _stamina = 5;
    _spirit = 5;
    _agility = 5;
    _intelligence = 5;
    _strength = 5;
    Range = AttackRange::CLOSE;
    _class = "Character";
    _race = "Koala";
    std::cout << _name << " Created" << std::endl;
}

int Character::CloseAttack()
{
    if (_energy < 10) {
        std::cout << _name << " out of power" << std::endl;
        return (0);
    } else {
        _energy -= 10;
        std::cout << _name << " strikes with a wooden stick" << std::endl;
        return (10 + _strength);
    }
}

int Character::RangeAttack()
{
    if (_energy < 10) {
        std::cout << _name << " out of power" << std::endl;
        return (0);
    } else {
        _energy -= 10;
        std::cout << _name << " tosses a stone" << std::endl;
        return (5 + _strength);
    }
}

void Character::Heal()
{
    if (_pv + 50 > 100)
        _pv = 100;
    else
        _pv += 50;
    std::cout << _name << " takes a potion" << std::endl;
}

void Character::RestorePower()
{
    _energy = 100;
    std::cout << _name << " eats" << std::endl;
}

void Character::TakeDamage(int damages)
{
    _pv -= damages;
    if (_pv <= 0)
        std::cout << getName() << " out of combat" << std::endl;
    else
        std::cout << getName() << " takes " << damages << " damage" << std::endl;
}

const std::string &Character::getName() const
{
    return (_name);
}

int Character::getLvl() const
{
    return (_level);
}
    
int Character::getPv() const
{
    return (_pv);
}

int Character::getPower() const
{
    return (_energy);
}