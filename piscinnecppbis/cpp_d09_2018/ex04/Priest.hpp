/*
** EPITECH PROJECT, 2019
** priest
** File description:
** priest
*/

#ifndef PRIEST_HPP_
#define PRIEST_HPP_

#include <string>
#include <iostream>
#include "Character.hpp"
#include "Mage.hpp"

class Priest : public Mage {
	public:
		Priest(const std::string &name, int level);
		~Priest();
        int CloseAttack();
        void Heal();

	protected:
	private:
};

#endif /* !PRIEST_HPP_ */
