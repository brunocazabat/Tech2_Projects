/*
** EPITECH PROJECT, 2019
** SickKoala.hpp
** File description:
** SickKoala.hpp
*/

#ifndef SICKKOALA_HPP_
	#define SICKKOALA_HPP_

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

class SickKoala {
	public:
		SickKoala(std::string name);
		~SickKoala();
		void poke();
		bool takeDrug(std::string drug);
		void overDrive(std::string str);
	private:
		std::string _name;
};

#endif /* !SICKKOALA_HPP_ */
