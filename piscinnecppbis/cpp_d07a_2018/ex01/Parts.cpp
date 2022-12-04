/*
** EPITECH PROJECT, 2019
** Parts
** File description:
** Parts
*/

#include "Parts.hpp"

Arms::Arms(const std::string &serial, bool functionnal)
{
    _serial = serial;
    _functional = functionnal;
}

Arms::~Arms()
{

}

bool Arms::isFunctionnal() const
{
    return (_functional);
}

std::string Arms::serial() const
{
    return (_serial);
}

void Arms::informations() const
{
    std::string functional;

    if (isFunctionnal())
        functional = "OK";
    else
        functional = "KO";
    std::cout << "\t[Parts] Arms " << _serial << " status : " << functional << std::endl;
}

Legs::Legs(const std::string &serial, bool functionnal)
{
    _serial = serial;
    _functional = functionnal;
}

Legs::~Legs()
{

}

bool Legs::isFunctionnal() const
{
    return (_functional);
}

std::string Legs::serial() const
{
    return (_serial);
}

void Legs::informations() const
{
    std::string functional;

    if (isFunctionnal() == true)
        functional = "OK";
    else
        functional = "KO";
    std::cout << "\t[Parts] Legs " << _serial << " status : " << functional << std::endl;
}

Head::Head(const std::string &serial, bool functionnal)
{
    _serial = serial;
    _functional = functionnal;
}

Head::~Head()
{

}

bool Head::isFunctionnal() const
{
    return (_functional);
}

std::string Head::serial() const
{
    return (_serial);
}

void Head::informations() const
{
    std::string functional;

    if (isFunctionnal() == true)
        functional = "OK";
    else
        functional = "KO";
    std::cout << "\t[Parts] Head " << _serial << " status : " << functional << std::endl;
}