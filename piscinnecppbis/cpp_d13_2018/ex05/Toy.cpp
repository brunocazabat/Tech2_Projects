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
    _errorHandler.type = Error::UNKNOWN;
}

Toy::Toy(const Toy &toy)
{
    _type = toy._type;
    _name = toy._name;
    _picture = new Picture(*toy._picture);
    _errorHandler.type = Error::UNKNOWN;
}

Toy::Toy(Toy::ToyType type, const std::string &name, const std::string &file)
{
    _type = type;
    _name = name;
    _picture = new Picture(file);
    _errorHandler.type = Error::UNKNOWN;
}

Toy::~Toy()
{
}

const Toy &Toy::operator=(const Toy &copy)
{
    _type = copy._type;
    _name = copy._name;
    _picture = new Picture(*copy._picture);
    _errorHandler = copy._errorHandler;
    return (*this);
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
    if (!_picture->getPictureFromFile(file)) {
        _errorHandler.type = Error::PICTURE;
        return (false);
    } else
        return (true);
}

void Toy::speak(std::string statement)
{
    std::cout << _name << " \"" << statement << "\"" << std::endl; 
}

bool Toy::speak_es(std::string statement)
{
    statement = statement;
    _errorHandler.type = Error::SPEAK;
    return (false);
}

const std::string Toy::Error::what() const
{
    if (type == SPEAK)
        return ("wrong mode");
    else if (type == PICTURE)
        return ("bad new illustration");
    else
        return ("");
}

const std::string Toy::Error::where() const
{
    if (type == SPEAK)
        return ("speak_es");
    else if (type == PICTURE)
        return ("setAscii");
    else
        return ("");
}

Toy::Error Toy::getLastError()
{
    return (_errorHandler);
}

Toy &Toy::operator<<(const std::string &str)
{
    _picture->data = str;
    return (*this);
}

std::ostream &operator<<(std::ostream &s, const Toy &toy)
{
    s << toy.getName() << std::endl << toy.getAscii() << std::endl;
    return (s);
}