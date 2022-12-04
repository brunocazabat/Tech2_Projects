/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/
#include "Warrior.hpp"
#include "Character.hpp"

Warrior::Warrior(std::string name, int lvl, std::string weaponName) : Character(name, lvl), _weaponName(weaponName)
{
    this->_Strength = 12;
    this->_Stamina = 12;
    this->_Intelligence = 12;
    this->_Spirit = 5;
    this->_Agility = 7;
    std::cout << "I'm " << name << " KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG" << std::endl;
}

Warrior::~Warrior()
{
}

int     Warrior::CloseAttack()
{
    if (Range == Character::CLOSE)
    {
        if (_Power >= 30)
	    {
	        _Power = _Power - 30;
	        std::cout << _Name << " strikes with his " << _weaponName << std::endl;
	        return (20 + _Strength);
	    }
        std::cout << _Name << " out of power" << std::endl;
        _Power = 0;
    }
    return (0);
}

int     Warrior::RangeAttack()
{
    if (Range == Character::RANGE)
    {
        if (_Power >= 10)
	    {
	        _Power = _Power - 10;
	        std::cout << _Name << " intercepts" << std::endl;
	        Range = Character::CLOSE;
	        return (0);
	    }
        std::cout << _Name << " out of power" << std::endl;
        _Power = 0;
    }
    return (0);
}