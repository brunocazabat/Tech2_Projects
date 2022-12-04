/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/

#ifndef PALADIN_HPP_
	#define PALADIN_HPP_

#include <string>
#include <iostream>
#include "Warrior.hpp"
#include "Priest.hpp"

class Paladin: public Warrior, public Priest 
{
	public:
		Paladin(std::string const &name, int lvl);
		~Paladin();
        using	Warrior::CloseAttack;
        using	Priest::RangeAttack;
        using	Priest::Heal;
        using	Warrior::RestorePower;
        int	    Intercept();
	protected:
	private:
};

#endif /* !PALADIN_HPP_ */