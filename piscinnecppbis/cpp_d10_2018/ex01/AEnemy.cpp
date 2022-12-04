/*
** EPITECH PROJECT, 2019
** enemy
** File description:
** enemy
*/

#include "AEnemy.hpp"

AEnemy::AEnemy(int hp, const std::string &type) : _hp(hp), _type(type)
{
}

AEnemy::~AEnemy()
{
}

void AEnemy::takeDamage(int damage)
{
    if (damage >= 0)
        _hp -= damage;
    if (_hp < 0)
        _hp = 0;
}

const std::string &AEnemy::getType() const
{
    return (_type);
}

int AEnemy::getHP() const
{
    return (_hp);
}

