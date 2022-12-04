/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/

#include "Woody.hpp"

Woody::Woody(std::string name, std::string file) : Toy(Toy::WOODY, name, file)
{
}

Woody::~Woody()
{
}

void    Woody::speak(std::string statement) {
    std::cout << "WOODY: " << this->name << " \"" << statement << "\""<< std::endl;
}