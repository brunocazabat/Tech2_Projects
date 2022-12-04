/*
** EPITECH PROJECT, 2019
** Federation
** File description:
** Federation
*/

#ifndef FEDERATION_HPP_
	#define FEDERATION_HPP_

#include <iostream>
#include <string>
#include "WarpSystem.hpp"
#include "Destination.hpp"
#include "Borg.hpp"

namespace Borg {
    class Ship;
}

namespace Federation
{
    class Ship
    {
      public:
        Ship(int length, int width, std::string name);
        ~Ship();
        void setupCore(WarpSystem::Core *core);
        void checkCore();
        bool move(int warp = 1, Destination d = VULCAN);
        WarpSystem::Core *getCore();

      protected:
      private:
        int _length;
        int _width;
        std::string _name;
        short _maxWarp;
        WarpSystem::Core *_core;
        Destination _home;
        Destination _location;
    };

    namespace Starfleet
    {
        class Captain
        {
            public:
                Captain(std::string name);
                ~Captain();
                std::string getName();
                int getAge();
                void setAge(int age);

            private:
                std::string _name;
                int _age;
        };

        class Ensign
        {
            public:
                Ensign(std::string name);
                ~Ensign();

            private:
                std::string _name;
        };

        class Ship
        {
          public:
            Ship(int length, int width, std::string name, short maxWarp, int torpedo = 0);
            Ship();
            ~Ship();
            void setupCore(WarpSystem::Core *core);
            void checkCore();
            void promote(Captain *captain);
            bool move(int warp = 6, Destination d = EARTH);
            int getShield();
            void setShield(int shield);
            int getTorpedo();
            void setTorpedo(int torpedo);
            void fire(Borg::Ship *target);
            void fire(int torpedoes, Borg::Ship *target);

          protected:
          private:
            int _length;
            int _width;
            std::string _name;
            short _maxWarp;
            WarpSystem::Core *_core;
            Destination _home;
            Destination _location;
            int _shield;
            int _photonTorpedo;
            Captain *_captain;
        };
    }
}

#endif /* !FEDERATION_HPP_ */
