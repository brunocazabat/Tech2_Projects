/*
** EPITECH PROJECT, 2019
** peon
** File description:
** peon
*/

#ifndef PEON_HPP_
#define PEON_HPP_

#include "Victim.hpp"
#include <string>
#include <iostream>

class Peon : public Victim {
	public:
		Peon(const std::string &name);
		~Peon();
        void getPolymorphed() const;

	protected:
	private:
};

#endif /* !PEON_HPP_ */
