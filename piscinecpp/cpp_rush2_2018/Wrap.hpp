/*
** EPITECH PROJECT, 2019
** Wrap.hpp
** File description:
** Wrap
*/

#ifndef WRAP_HPP_
	#define WRAP_HPP_

#include "Object.hpp"

class Wrap : public Object {
	public:
		Wrap();
		~Wrap() override = default;

        virtual void wrapMeThat(Object *_obj) = 0;
        bool getOpen();
        bool getEmpty();
        Object *getObject();
        void isTaken();
        void putObject(Object *Object);
	    //Object takeObject();

	protected:
        bool _isOpen;
        bool _isEmpty;
        Object *_obj;
	private:
};

#endif /* !WRAP_HPP_ */
