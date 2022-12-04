/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/

#ifndef MAGE_HPP_
	#define MAGE_HPP_

#include <iostream>
#include "Character.hpp"

class Mage : virtual public Character {
	public:
		Mage(std::string, int lvl);
		~Mage();
        int     CloseAttack();
        int     RangeAttack();
        void    Heal();
        void    RestorePower();
	protected:
	private:
};

#endif /* !MAGE_HPP_ */