/*
** EPITECH PROJECT, 2019
** sorc
** File description:
** sorc
*/

#ifndef SORCERER_HPP_
#define SORCERER_HPP_

#include <string>
#include <iostream>
#include "Victim.hpp"

class Sorcerer {
	public:
		Sorcerer(const std::string &name, const std::string &title);
		~Sorcerer();
        std::string getName() const;
        std::string getTitle() const;
        void polymorph(const Victim &victim) const;

	protected:
	private:
        std::string _name;
        std::string _title;
};

std::ostream &operator<<(std::ostream &s, const Sorcerer &sorcerer);

#endif /* !SORCERER_HPP_ */