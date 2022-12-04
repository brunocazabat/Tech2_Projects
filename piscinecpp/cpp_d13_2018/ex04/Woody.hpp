/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/

#ifndef WOODY_HPP_
	#define WOODY_HPP_

#include <iostream>
#include <string>
#include "Toy.hpp"

class Woody : public Toy {
	public:
		Woody(std::string name, std::string file = "woody.txt");
		~Woody();
		void	speak(std::string statement);
	protected:
	private:
};

#endif /* !WOODY_HPP_ */
