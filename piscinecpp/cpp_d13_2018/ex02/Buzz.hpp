/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/

#ifndef BUZZ_HPP_
	#define BUZZ_HPP_

#include <iostream>
#include <string>
#include "Toy.hpp"

class Buzz : public Toy {
	public:
		Buzz(std::string name, std::string file = "buzz.txt");
		~Buzz();

	protected:
	private:
};

#endif /* !BUZZ_HPP_ */
