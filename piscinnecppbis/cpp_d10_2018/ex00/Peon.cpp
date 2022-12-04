/*
** EPITECH PROJECT, 2019
** peon
** File description:
** peon
*/

#include "Peon.hpp"


Peon::Peon(const std::string &name) : Victim(name)
{
    std::cout << "Zog zog." << std::endl;
}

Peon::~Peon()
{
    std::cout << "Bleuark..." << std::endl;
}

void Peon::getPolymorphed() const
{
    std::cout << getName() << " has been turned into a pink pony!" << std::endl;
}