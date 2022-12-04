/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/
#include "Mage.hpp"

Mage::Mage(std::string name, int lvl) : Character(name, lvl)
{
    this->_Strength = 6;
    this->_Stamina = 6;
    this->_Intelligence = 12;
    this->_Spirit = 11;
    this->_Agility = 7;
    std::cout << _Name << " teleported" << std::endl;
}

Mage::~Mage()
{
}

int	Mage::CloseAttack()
{
    if (Range == Mage::CLOSE)
    {
        if (_Power >= 10)
	    {
	        _Power = _Power - 10;
	        Range = Mage::RANGE;
	        std::cout << _Name << " blinks" << std::endl;
	        return (0);
	    }
        std::cout << _Name << " out of power" << std::endl;
        _Power = 0;
    }
    return (0);
}

int     Mage::RangeAttack()
{
    if (Range == Mage::RANGE)
    {
        if (_Power >= 25)
	    {
	        _Power = _Power - 25;
	        std::cout << _Name << " launches a fire ball" << std::endl;
	        return (20 + _Spirit);
	    }
        std::cout << _Name << " out of power" << std::endl;
        _Power = 0;
    }
    return (0);
}

void    Mage::RestorePower()
{
    _Power += 50 + _Intelligence;
    if (_Power > 100)
    _Power = 100;
    std::cout << _Name << " takes a mana potion" << std::endl;
}

void    Mage::Heal()
{
    if (_Health <= 50)
        _Health = _Health + 50;
    else
        _Health = 100;
    std::cout << _Name << " takes a potion" << std::endl;
}