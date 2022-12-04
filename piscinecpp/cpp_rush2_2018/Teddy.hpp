/*
** EPITECH PROJECT, 2019
** Teddy.hpp
** File description:
** Teddy
*/

#ifndef TEDDY_HPP_
	#define TEDDY_HPP_

#include "Toy.hpp"

class Teddy : public Toy {
	public:
		Teddy(std::string title) : Toy(title) {
			this->_taken = false;
		};
		~Teddy() override = default;
		void isTaken();
	protected:
	private:
};

#endif /* !TEDDY_HPP_ */
