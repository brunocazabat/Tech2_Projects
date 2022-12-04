/*
** EPITECH PROJECT, 2019
** Box.hpp
** File description:
** Box
*/

#ifndef BOX_HPP_
	#define BOX_HPP_

#include "Wrap.hpp"

class Box : public Wrap {
	public:
		Box();
		~Box() override = default;

        Object *openMe();
        void closeMe();
        void wrapMeThat(Object *obj);

	protected:
	private:
};

#endif /* !BOX_HPP_ */
