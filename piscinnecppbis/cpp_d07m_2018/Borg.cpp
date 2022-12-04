/*
** EPITECH PROJECT, 2019
** Borg
** File description:
** Borg
*/

#include "Federation.hpp"

namespace Borg {
    Ship::Ship(int weaponFrequency, short repair)
    {
        _side = 300;
        _maxWarp = 9;
        _home = UNICOMPLEX;
        _location = UNICOMPLEX;
        _shield = 100;
        _weaponFrequency = weaponFrequency;
        _repair = repair;
        std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally." << std::endl;
        std::cout << "Your biological characteristics and technologies will be assimilated." << std::endl;
        std::cout << "Resistance is futile." << std::endl;
    }

    Ship::~Ship()
    {
    }

    void Ship::setupCore(WarpSystem::Core *core)
    {
        _core = core;
    }

    void Ship::checkCore()
    {
        WarpSystem::QuantumReactor *reactor = _core->checkReactor();
        std::string stability = (reactor->isStable()) ? "Everything is in order." : "Critical failure imminent.";
        std::cout << stability << std::endl;
    }

    bool Ship::move(int warp, Destination d)
    {
        WarpSystem::QuantumReactor *reactor = _core->checkReactor();

        if (warp <= _maxWarp && d != _location && reactor->isStable()) {
            _location = d;
            return (true);
        } else
            return (false);
    }

    int Ship::getShield()
    {
        return (_shield);
    }

    void Ship::setShield(int shield)
    {
        _shield = shield;
    }
    
    int Ship::getWeaponFrequency()
    {
        return (_weaponFrequency);
    }
    
    void Ship::setWeaponFrequency(int frequency)
    {
        _weaponFrequency = frequency;
    }

    short Ship::getRepair()
    {
        return (_repair);
    }
    
    void Ship::setRepair(short repair)
    {
        _repair = repair;
    }

    void Ship::fire(Federation::Starfleet::Ship *target)
    {
        int ennemyShield = target->getShield();

        target->setShield(ennemyShield - _weaponFrequency);
        std::cout << "Firing on target with " << _weaponFrequency << "GW frequency." << std::endl;
    }

    void Ship::fire(Federation::Ship *target)
    {
        WarpSystem::Core *ennemyCore = target->getCore();
        WarpSystem::QuantumReactor *ennemyReactor = ennemyCore->checkReactor();
        ennemyReactor->setStability(false);

        std::cout << "Firing on target with " << _weaponFrequency << "GW frequency." << std::endl;
    }

    void Ship::repair()
    {
        if (_repair == 0)
            std::cout << "Energy cells depleted, shield weakening." << std::endl;
        else {
            _repair -= 1;
            this->setShield(100);
            std::cout << "Begin shield re-initialisation... Done. Awaiting further instructions." << std::endl;
        }
    }
}