/*
** EPITECH PROJECT, 2019
** Borg
** File description:
** Borg
*/

#ifndef BORG_HPP_
	#define BORG_HPP_

#include <iostream>
#include <string>
#include "Federation.hpp"

namespace Federation {
    class Ship;
    namespace Starfleet {
        class Captain;
        class Ensign;
        class Ship;
    }
}

namespace Borg {
    class Ship {
	    public:
		    Ship(int weaponFrequency, short repair = 3);
		    ~Ship();
            void setupCore(WarpSystem::Core *core);
            void checkCore();
            bool move(int warp = 9, Destination d = UNICOMPLEX);
            int getShield();
            void setShield(int shield);
            int getWeaponFrequency();
            void setWeaponFrequency(int frequency);
            short getRepair();
            void setRepair(short repair);
            void fire(Federation::Starfleet::Ship *target);
            void fire(Federation::Ship *target);
            void repair();

    	protected:
	    private:
            int _side ;
            short _maxWarp ;
            WarpSystem::Core *_core;
            Destination _home;
            Destination _location;
            int _shield ; // set to 100 upon construction
            int _weaponFrequency ; // provided upon construction
            short _repair ; // can be provided . if not , set to 3 upon construction
    };
}

#endif /* !BORG_HPP_ */