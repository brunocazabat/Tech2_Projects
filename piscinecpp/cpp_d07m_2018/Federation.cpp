/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/

#include "Federation.hpp"

Federation::Starfleet::Ship::Ship(int length, int width, std::string name, short maxWarp)
{
    this->_length = length;
    this->_width = width;
    this->_name = name;
    this->_maxWarp = maxWarp;

    std::cout << "The ship USS " << name << " has been finished." << std::endl;
    std::cout << "It is " << length << " m in length and " << width << " m in width." << std::endl;
    std::cout << "It can go to Warp " << maxWarp << "!" << std::endl;
}

Federation::Starfleet::Ship::~Ship()
{

}

void    Federation::Starfleet::Ship::setupCore()
{
}