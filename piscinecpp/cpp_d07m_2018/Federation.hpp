/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

#ifndef FEDERATION_HPP_
	#define FEDERATION_HPP_

namespace Federation {
    namespace Starfleet {
        class Ship {
            public:
                Ship(int length, int width, std::string name, short maxWarp);
                ~Ship();
                void setupCore();
                void checkCore();
            protected:
            private:
                int _length;
                int _width;
                std::string _name;
                short _maxWarp;
        };
        class Federation {
	        public:
		        Federation();
		        ~Federation();
	        protected:
	        private:
        };
    };
};

#endif /* !FEDERATION_HPP_ */
