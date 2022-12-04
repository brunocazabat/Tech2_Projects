/*
** EPITECH PROJECT, 2019
** SickKoala.cpp
** File description:
** SickKoala.cpp
*/

#include "SickKoala.hpp"

SickKoala::SickKoala(std::string name) : _name(name)
{
}

SickKoala::~SickKoala()
{
    std::cout << "Mr." << _name << ": Kreooogg!! I'm cuuuured!" << std::endl;
}

void SickKoala::poke()
{
    std::cout << "Mr." << _name << ": Gooeeeeerrk!!" << std::endl;
}

std::string SickKoala::getName()
{
    return (_name);
}

bool SickKoala::takeDrug(std::string drug)
{
    std::string lowCase = drug;
    unsigned int i = 0;

    for (i = 0; i < drug.size(); i++)
        lowCase[i] = tolower(drug[i]);
    if (lowCase == "mars") {
        std::cout << "Mr." << _name << ": Mars, and it kreogs!" << std::endl;
        return (true);
    } else if (drug == "Buronzand") {
        std::cout << "Mr." << _name << ": And you'll sleep right away!" << std::endl;
        return (true);
    } else {
        std::cout << "Mr." << _name << ": Goerkreog!" << std::endl;
        return (false);
    }
}

void replace(std::string &str, std::string toFind, std::string toReplace)
{
	size_t pos = str.find(toFind);

	while (pos != std::string::npos) {
		str.replace(pos, toFind.size(), toReplace);
		pos = str.find(toFind, pos + toReplace.size());
	}
}

void SickKoala::overDrive(std::string str)
{
    replace(str, "Kreog!", "1337!");
    std::cout << "Mr.[name]: " << str << std::endl; 
}