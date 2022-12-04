/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/
#include "Toy.hpp"

Toy::Toy() : type(Toy::BASIC_TOY), name("toy"), picture(Picture()) {
}

Toy::Toy(ToyType type, std::string name, std::string file) : type(type), name(name), picture(Picture(file)) {
}

Toy::Toy(Toy &toy) : type(toy.getType()), name(toy.getName()), picture(toy.getAscii())
{
}

Toy::~Toy()
{
}

std::string	    Toy::getName() const {
    return this->name;
}

Toy::ToyType    Toy::getType() const {
    return this->type;
}

std::string     Toy::getAscii() const {
  return this->picture.data;
}

void            Toy::setName(std::string const name) {
    this->name = name;
}

bool            Toy::setAscii(std::string const data) {
    return this->picture.getPictureFromFile(data);
}

void            Toy::speak(std::string statement) {
    std::cout << this->name << " \"" << statement << "\""<<std::endl;
}

std::ostream &operator<<(std::ostream &os, Toy &toy)
{
  os << toy.getName() << std::endl << toy.getAscii() << std::endl;
  return os;
}