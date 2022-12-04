/*
** EPITECH PROJECT, 2019
** federation
** File description:
** federation
*/

#include "Federation.hpp"

namespace Federation
{
    Ship::Ship(int length, int width, std::string name)
    {
        _length = length;
        _width = width;
        _name = name;
        _maxWarp = 1;
        _home = VULCAN;
        _location = VULCAN;
        std::cout << "The independant ship " << _name << " just finished its construction." << std::endl;
        std::cout << "It is " << _length << " m in length and " << _width << " m in width." << std::endl;
    }

    Ship::~Ship()
    {
    }

    void Ship::setupCore(WarpSystem::Core *core)
    {
        _core = core;
        std::cout << _name << ": The core is set." << std::endl;
    }

    void Ship::checkCore()
    {
        WarpSystem::QuantumReactor *reactor = _core->checkReactor();
        std::string core = (reactor->isStable()) ? "stable" : "unstable";

        std::cout << _name << ": The core is " << core << " at the time." << std::endl;
    }

    WarpSystem::Core *Ship::getCore()
    {
        return (_core);
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

    namespace Starfleet
    {
        Captain::Captain(std::string name) : _name(name)
        {
        }

        Captain::~Captain()
        {
        }
        
        std::string Captain::getName()
        {
            return (_name);
        }
        
        int Captain::getAge()
        {
            return (_age);
        }
        
        void Captain::setAge(int age)
        {
            _age = age;
        }

        Ensign::Ensign(std::string name) : _name(name)
        {
            std::cout << "Ensign " << _name << ", awaiting orders." << std:: endl;
        }

        Ensign::~Ensign()
        {
        }

        Ship::Ship(int length, int width, std::string name, short maxWarp, int torpedo)
        {
            _length = length;
            _width = width;
            _name = name;
            _maxWarp = maxWarp;
            _home = EARTH;
            _location = EARTH;
            _shield = 100;
            _photonTorpedo = torpedo;
            std::cout << "The ship USS " << _name << " has been finished." << std::endl;
            std::cout << "It is " << _length << " m in length and " << _width << " m in width." << std::endl;
            std::cout << "It can go to Warp " << _maxWarp << "!" << std::endl;
            if (torpedo > 0)
               std::cout << "Weapons are set: " << _photonTorpedo << " torpedoes ready." << std::endl;
        }

        Ship::Ship() {
            _length = 289;
            _width = 132;
            _name = "Enterprise";
            _maxWarp = 6;
            _home = EARTH;
            _location = EARTH;
            _shield = 100;
            _photonTorpedo = 0;
            std::cout << "The ship USS " << _name << " has been finished." << std::endl;
            std::cout << "It is " << _length << " m in length and " << _width << " m in width." << std::endl;
            std::cout << "It can go to Warp " << _maxWarp << "!" << std::endl;
        }

        Ship::~Ship()
        {
        }

        void Ship::setupCore(WarpSystem::Core *core)
        {
            _core = core;
            std::cout << "USS " << _name << ": The core is set." << std::endl;
        }

        void Ship::checkCore()
        {
            WarpSystem::QuantumReactor *reactor = _core->checkReactor();
            std::string core = (reactor->isStable()) ? "stable" : "unstable";

            std::cout << "USS " << _name << ": The core is " << core << " at the time." << std::endl;
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

        int Ship::getTorpedo()
        {
            return (_photonTorpedo);
        }

        void Ship::setTorpedo(int torpedo)
        {
            _photonTorpedo = torpedo;
        }

        void Ship::fire(Borg::Ship *target)
        {
            int ennemyShield = target->getShield();

            if (_photonTorpedo == 0) {
                std::cout << _name << ": Not enough torpedoes to fire, " << _captain->getName() << "!" << std::endl;
            } else {
                _photonTorpedo -= 1;
                target->setShield(ennemyShield - 50);
                std::cout << _name << ": Firing on target. " << _photonTorpedo << " remaining." << std::endl;
                if (_photonTorpedo == 0)
                    std::cout << _name << ": No more torpedo to fire, " << _captain->getName() << "!" << std::endl;
            }
        }

        void Ship::fire(int torpedoes, Borg::Ship *target)
        {
            int ennemyShield = target->getShield();

            if (_photonTorpedo - torpedoes < 0) {
                std::cout << _name << ": Not enough torpedoes to fire, " << _captain->getName() << "!" << std::endl;
            } else {
                _photonTorpedo -= torpedoes;
                target->setShield(ennemyShield - (50 * torpedoes));
                std::cout << _name << ": Firing on target. " << _photonTorpedo << " torpedoes remaining." << std::endl;
                if (_photonTorpedo == 0)
                    std::cout << _name << ": No more torpedo to fire, " << _captain->getName() << "!" << std::endl;
            }
        }

        void Ship::promote(Captain *captain)
        {
            _captain = captain;
            std::cout << _captain->getName() << ": I'm glad to be the captain of the USS " << _name << "." << std::endl;
        }
    }
}