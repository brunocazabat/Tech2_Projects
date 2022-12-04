/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/

#ifndef PRIEST_HPP_
	#define PRIEST_HPP_

#include <iostream>
#include "Mage.hpp"

class Priest: public Mage {
	public:
		Priest(std::string name, int lvl);
		~Priest();
        int	    CloseAttack();
        int	    RangeAttack();
        void	Heal();
	protected:
	private:
};

#endif /* !PRIEST_HPP_ */