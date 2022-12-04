/*
** EPITECH PROJECT, 2019
** weapon
** File description:
** weapon
*/

#include "AWeapon.hpp"

AWeapon::AWeapon(const std::string &name, int apcost, int damage) : _name(name), _apCost(apcost), _damages(damage)
{
}

AWeapon::~AWeapon()
{
}

const std::string &AWeapon::getName() const
{
    return (_name);
}

int AWeapon::getAPCost() const
{
    return (_apCost);
}

int AWeapon::getDamage() const
{
    return (_damages);
}