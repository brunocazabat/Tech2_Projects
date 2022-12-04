/*
** EPITECH PROJECT, 2019
** LittlePony.hpp
** File description:
** LittlePony
*/

#ifndef LITTLEPONY_HPP_
	#define LITTLEPONY_HPP_

#include "Toy.hpp"

class LittlePony : public Toy {
	public:
		LittlePony(std::string title) : Toy(title) {
			this->_taken = false;
		};
		~LittlePony() override = default;
		void isTaken();		

	protected:
	private:
};

#endif /* !LITTLEPONY_HPP_ */
