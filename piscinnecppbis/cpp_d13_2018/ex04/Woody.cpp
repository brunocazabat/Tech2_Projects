/*
** EPITECH PROJECT, 2019
** woody
** File description:
** woody
*/

#include "Woody.hpp"

Woody::Woody(const std::string &name, const std::string &ascii) : Toy(WOODY, name, ascii)
{
}

Woody::~Woody()
{
}

void Woody::speak(std::string statement)
{
    std::cout << "WOODY: "<< _name << " \"" << statement << "\"" << std::endl; 
}