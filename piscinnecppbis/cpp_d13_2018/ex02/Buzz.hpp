/*
** EPITECH PROJECT, 2019
** buzz
** File description:
** buzz
*/

#ifndef BUZZ_HPP_
#define BUZZ_HPP_

#include "Toy.hpp"

class Buzz : public Toy {
	public:
		Buzz(const std::string &name, const std::string &ascii = "buzz.txt");
		~Buzz();

	protected:
	private:
};

#endif /* !BUZZ_HPP_ */
