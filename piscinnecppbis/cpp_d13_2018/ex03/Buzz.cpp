/*
** EPITECH PROJECT, 2019
** buzz
** File description:
** buzz
*/

#include "Buzz.hpp"

Buzz::Buzz(const std::string &name, const std::string &ascii) : Toy(BUZZ, name, ascii)
{
}

Buzz::~Buzz()
{
}

void Buzz::speak(std::string statement)
{
    std::cout << "BUZZ: "<< _name << " \"" << statement << "\"" << std::endl; 
}