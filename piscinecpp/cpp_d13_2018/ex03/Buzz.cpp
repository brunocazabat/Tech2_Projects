/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/

#include "Buzz.hpp"

Buzz::Buzz(std::string name, std::string file) : Toy(Toy::BUZZ, name, file)
{
}

Buzz::~Buzz()
{
}

void    Buzz::speak(std::string statement) {
    std::cout << "BUZZ: " << this->name << " \"" << statement << "\""<< std::endl;
}