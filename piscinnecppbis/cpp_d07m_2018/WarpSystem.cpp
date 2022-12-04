/*
** EPITECH PROJECT, 2019
** WarpSystem
** File description:
** WarpSystem
*/

#include "WarpSystem.hpp"

namespace WarpSystem
{
    QuantumReactor::QuantumReactor() : _stability(true)
    {
    }

    QuantumReactor::~QuantumReactor()
    {
    }

    bool QuantumReactor::isStable()
    {
        return (_stability);
    }

    void QuantumReactor::setStability(bool stability)
    {
        _stability = stability;
    }

     Core::Core(QuantumReactor *coreReactor) : _coreReactor(coreReactor)
    {
    }

    Core::~Core()
    {
    }
    
    QuantumReactor *Core::checkReactor()
    {
        return (_coreReactor);
    }
}