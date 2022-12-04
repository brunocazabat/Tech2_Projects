/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/

#ifndef WARRIOR_HPP_
	#define WARRIOR_HPP_

#include <iostream>
#include <string>
#include "Character.hpp"

class Warrior: public Character
{
	public:
		Warrior(std::string name, int lvl, std::string weaponName = "hammer");
		~Warrior();
        int	CloseAttack();
        int	RangeAttack();
	protected:
	private:
        std::string _weaponName;
};

#endif /* !WARRIOR_HPP_ */
