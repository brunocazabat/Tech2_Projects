/*
** EPITECH PROJECT, 2019
** e
** File description:
** e
*/

#include "RadScorpion.hpp"

RadScorpion::RadScorpion() : AEnemy(80, "RadScorpion")
{
    std::cout << "* click click click *" << std::endl;
}

RadScorpion::~RadScorpion()
{
    std::cout << "* SPROTCH *" << std::endl;
}