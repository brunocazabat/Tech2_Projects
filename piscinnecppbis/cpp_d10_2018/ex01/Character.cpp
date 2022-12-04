/*
** EPITECH PROJECT, 2019
** character
** File description:
** character
*/

#include "Character.hpp"

Character::Character(const std::string &name) : _name(name), _Ap(40)
{
}

Character::~Character()
{
}

const std::string &Character::getName() const
{
    return (_name);
}

int Character::getAP() const
{
    return (_Ap);
}

const std::string &Character::getWeaponName() const
{
    return (this->_weapon->getName());
}

bool Character::isWeapon() const
{
    if (_weapon)
        return (true);
    return (false);
}

void Character::recoverAP()
{
    if (_Ap > 30)
        _Ap = 40;
    else
        _Ap += 10;
}

void Character::equip(AWeapon *weapon)
{
    _weapon = weapon;
}

void Character::attack(AEnemy *enemy)
{
    if (_weapon && _Ap >= _weapon->getAPCost()) {
        std::cout << _name << " attacks " << enemy->getType() << " with a " << _weapon->getName() << std::endl;
        _weapon->attack();        
        enemy->takeDamage(_weapon->getDamage());
        _Ap -= _weapon->getAPCost();
        if (enemy->getHP() <= 0)
            enemy->~AEnemy();
    }
}

std::ostream &operator<<(std::ostream &s, const Character &character)
{
    if (character.isWeapon() == false)
        s << character.getName() << " has " << character.getAP() << " AP and is unarmed" << std::endl;
    else
        s << character.getName() << " has " << character.getAP() << " AP and wields a " << character.getWeaponName() << std::endl;
    return (s);
}
