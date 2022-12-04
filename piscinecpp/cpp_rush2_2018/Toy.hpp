/*
** EPITECH PROJECT, 2019
** Toy.hpp
** File description:
** Toy
*/

#ifndef TOY_HPP_
	#define TOY_HPP_

#include "Object.hpp"

class Toy : public Object {
	public:
		Toy(std::string title) {
			this->_title = title;
			this->_typeObj = TOY;
			std::cout << "Toy " << this->getTitle() << " Created" << std::endl;                                                                        
		};
		virtual ~Toy() = default;
	protected:
	private:
};

#endif /* !TOY_HPP_ */