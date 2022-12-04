/*
** EPITECH PROJECT, 2019
** IElf.cpp
** File description:
** cpp
*/

#ifndef IELF_HPP_
	#define IELF_HPP_

#include "Object.hpp"

class Object;

class IElf {
	public:
		virtual ~IElf() = 0;
		virtual void pressINBtn() = 0;
		virtual void pressOUTBtn() = 0;
		virtual void openMe() = 0;
        virtual void closeMe();
		virtual void isTaken() = 0;
        virtual void wrapMeThat() = 0;
		virtual void putObject() = 0;
		virtual void takeObject(std::string nameObject) = 0;
		virtual std::string lookTable() = 0;
		virtual std::string lookConvoyerbelt();
};

#endif /* !IELF_HPP_ */
