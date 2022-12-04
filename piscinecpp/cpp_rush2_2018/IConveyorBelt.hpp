/*
** EPITECH PROJECT, 2019
** IConveyorBelt
** File description:
** Conveyor
*/

#ifndef ICONVEYORBELT_HPP_
	#define ICONVEYORBELT_HPP_

#include "Object.hpp"
#include <iostream>
#include <string>

class IConveyorBelt {
	public:
		virtual ~IConveyorBelt() {}
        	virtual IConveyorBelt *createConveyorBelt() = 0;


};

#endif /* !ICONVEYORBELT_HPP_ */
