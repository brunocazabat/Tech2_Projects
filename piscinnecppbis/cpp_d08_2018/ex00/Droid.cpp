/*
** EPITECH PROJECT, 2019
** droid
** File description:
** droid
*/

#include "Droid.hpp"

Droid::Droid(std::string serial)
{
    _id = serial;
    _energy = 50;
    _status = new std::string("Standing by");
    std::cout << "Droid '" << getId() << "', Activated" << std::endl;
}

Droid::Droid(const Droid &copy)
{
    _id = copy._id;
    _energy = copy._energy;
    _status = copy._status;
    std::cout << "Droid '" << _id << "' Activated, Memory Dumped" << std::endl;
}

Droid::~Droid()
{
    std::cout << "Droid '" << getId() << "' Destroyed" << std::endl;
}

Droid &Droid::operator=(Droid &copy)
{
    _id = copy._id;
    _energy = copy._energy;
    _status = copy._status;
    return (copy);
}

bool Droid::operator==(const Droid &other)
{
    return(_id == other._id && _energy == other._energy && _attack == other._attack && _toughness == other._toughness && _status == other._status);
}

bool Droid::operator!=(const Droid &other)
{
    return(_id != other._id || _energy != other._energy || _attack != other._attack || _toughness != other._toughness || _status != other._status);
}

void Droid::setId(std::string id)
{
    _id = id;
}

void Droid::setEnergy(size_t energy)
{
    _energy = energy;
}
        
void Droid::setStatus(std::string *status)
{
    _status = status;
}
    
std::string Droid::getId()
{
    return (_id);
}

size_t Droid::getEnergy()
{
    return (_energy);
}

size_t Droid::getAttack()
{
    return (_attack);
}

size_t Droid::getToughness()
{
    return (_toughness);
}

std::string *Droid::getStatus()
{
    return (_status);
}

void Droid::operator<<(size_t &battery)
{
    size_t need = 100 - _energy;

    if (need <= battery) {
        battery -= need;
        this->setEnergy(_energy + need);
    } else if (need > battery) {
        battery = 0;
        this->setEnergy(_energy + battery);
    }
}

std::ostream &operator<<(std::ostream &s, Droid &droid)
{
    s << "Droid '" << droid.getId() << "', " << *droid.getStatus() << ", " << droid.getEnergy();
    return (s);
}