/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/
#include "WarpSystem.hpp"

bool    WarpSystem::QuantumReactor::isStable()
{
    return (this->_stability);
}

void    WarpSystem::QuantumReactor::setStability(bool stability)
{
    this->_stability = stability;
}

WarpSystem::QuantumReactor::QuantumReactor()
{
    this->_stability = true;
}

WarpSystem::QuantumReactor::~QuantumReactor()
{
}

WarpSystem::WarpSystem::WarpSystem()
{

}

WarpSystem::WarpSystem::~WarpSystem()
{

}