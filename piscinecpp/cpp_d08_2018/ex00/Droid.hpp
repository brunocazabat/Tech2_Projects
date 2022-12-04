/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/

#ifndef DROID_HPP_
	#define DROID_HPP_

#include <string>
#include <iostream>

class Droid {
	public:
		Droid(std::string serial = "");
		~Droid();
	protected:
	private:
        std::string Id;
        size_t Energy;
        const size_t Attack = 25;
        const size_t Toughness = 15;
        std::string *Status;
};

#endif /* !DROID_HPP_ */
