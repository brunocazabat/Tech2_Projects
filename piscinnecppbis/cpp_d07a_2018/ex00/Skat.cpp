/*
** EPITECH PROJECT, 2019
** stimpak
** File description:
** stimpak
*/

#include "Skat.hpp"

Skat::Skat(const std::string &name, int stimPaks)
{
    _name = name;
    _stimPaks = stimPaks;
}

Skat::Skat(const int &stimPaks)
{
    _name = "bob";
    _stimPaks = stimPaks;
}

Skat::~Skat()
{
}

int &Skat::stimPaks()
{
    return (_stimPaks);
}

int &Skat::stimPaks(int number)
{
    _stimPaks = number;

    return (_stimPaks);
}

const std ::string &Skat::name()
{
    std::string &name = _name;
    return (name);
}

void Skat::shareStimPaks(int number, int &stock)
{
    if (_stimPaks - number >= 0) {
        _stimPaks -= number;
        stock += number;
        std::cout << "Keep the change." << std::endl;
    } else {
        std::cout << "Don't be greedy" << std::endl;
    }
}

void Skat::addStimPaks(unsigned int number)
{
    _stimPaks += number;
    if (number == 0)
        std::cout << "Hey boya, did you forget something?" << std::endl;
}
    
void Skat::useStimPaks()
{
    if (_stimPaks == 0)
        std::cout << "Mediiiiiic" << std::endl;
    else {
        _stimPaks -= 1;
        std::cout << "Time to kick some ass and chew bubble gum." << std::endl;
    }
}

void Skat::status()
{
    std::cout << "Soldier " << _name << " reporting " << _stimPaks << " stimpaks remaining sir!" << std::endl;
}