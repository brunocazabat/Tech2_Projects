/*
** EPITECH PROJECT, 2019
** Object.hpp
** File description:
** Object
*/

#ifndef OBJECT_HPP_
	#define OBJECT_HPP_

#include <iostream>
#include <string>
#include "IElf.hpp"

class IElf;

class Object {
	public:
		Object();
		virtual ~Object();

		enum typeObj {
			TOY,
			BOX,
			GIFTPAPER			
		};

		virtual void isTaken();
		bool getTaken();
		std::string getTitle();

	protected:
		std::string _title;
		bool _taken = false;
		typeObj _typeObj;
	private:
};

#endif /* !OBJECT_HPP_ */
