/*
** EPITECH PROJECT, 2019
** toy
** File description:
** toy
*/

#include "Toy.hpp"

Toy::Toy()
{
    _type = BASIC_TOY;
    _name = "toy";
    _picture = new Picture;
    _picture->data = "";
}

Toy::Toy(Toy::ToyType type, const std::string &name, const std::string &file)
{
    _type = type;
    _name = name;
    _picture = new Picture(file);
}

Toy::~Toy()
{
}

Toy::ToyType Toy::getType() const
{
    return (_type);
}

std::string Toy::getName() const
{
    return (_name);
}

void Toy::setName(const std::string &name)
{
    _name = name;    
}

std::string Toy::getAscii() const
{
    return (_picture->data);
}

bool Toy::setAscii(const std::string &file)
{
    return (_picture->getPictureFromFile(file));
}