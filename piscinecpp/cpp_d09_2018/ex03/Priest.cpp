/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/

#include "Priest.hpp"

Priest::Priest(std::string name, int lvl) : Mage(name, lvl)
{
    this->_Strength = 4;
    this->_Stamina = 4;
    this->_Intelligence = 42;
    this->_Spirit = 21;
    this->_Agility = 2;
    std::cout << _Name << " enters in the order" << std::endl;  
}

Priest::~Priest()
{
}

int	Priest::CloseAttack()
{
    if (Range == Priest::CLOSE)
    {
        if (_Power >= 10)
	    {
	        _Power = _Power - 10;
	        std::cout << _Name << " uses a spirit explosion" << std::endl;
	        return (10 + _Spirit);
	    }
        std::cout << _Name << " out of power" << std::endl;
        _Power = 0;
    }
    return (0);
}

int	Priest::RangeAttack()
{
    if (Range == Priest::RANGE)
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

void	Priest::Heal()
{
    if (_Power >= 10)
    {
        _Power = _Power - 10;
        _Health = _Health + 70;
        if (_Health > 100)
	        _Health = 100;
        std::cout << _Name << " casts a little heal spell" << std::endl;
    }
    else
    {
        _Power = 0;
        std::cout << _Name << " out of power" << std::endl;
    }
}