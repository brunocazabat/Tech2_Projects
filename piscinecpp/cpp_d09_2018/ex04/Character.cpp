/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/
#include "Character.hpp"

Character::Character(const std::string &name, int level)
{
    this->Range = CLOSE;
    this->_Name = name;
    this->_Level = level;
    this->_Power = 100;
    this->_Health = 100;
    this->_Strength = 5; 
    this->_Stamina = 5; 
    this->_Intelligence = 5;
    this->_Spirit = 5;
    this->_Agility = 5;
    std::cout << name << " Created" << std::endl;
}

Character::~Character()
{
}

const std::string   &Character::getName() const
{
    return (_Name);
}

int     Character::getLvl() const
{
    return (_Level);
}

int     Character::getPv() const
{
    return (_Health);
}

int     Character::getPower() const
{
    return (_Power);
}

int     Character::CloseAttack()
{
    if (_Power > 10)
    {
        _Power = _Power - 10;
        std::cout << _Name <<  " strikes with a wooden stick" << std::endl;
        return (10 + _Strength);
    }
    std::cout << _Name << " out of power" << std::endl;
    _Power = 0;
    return (0);    
}

int     Character::RangeAttack()
{
    if (_Power > 10)
    {
        _Power = _Power - 10;
        std::cout << _Name << " tosses a stone" << std::endl;
        return (5 + _Strength);
    }
  std::cout << _Name << " out of power" << std::endl;
  _Power = 0;
  return (0);
}

void    Character::Heal()
{
    if (_Health <= 50)
    _Health = _Health + 50;
  else
    _Health = 100;
  std::cout << _Name << " takes a potion" << std::endl;
}

void    Character::RestorePower()
{
    _Power = 100;
    std::cout << _Name << " eats" << std::endl;
}

void    Character::TakeDamage(int _Damage)
{
    _Health = _Health - _Damage;
  if (_Health > 0)
    std::cout << _Name << " takes " << _Damage <<" damage" << std::endl;
  else
    std::cout << _Name << " out of combat" << std::endl;
}