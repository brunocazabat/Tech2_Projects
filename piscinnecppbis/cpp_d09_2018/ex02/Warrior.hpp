/*
** EPITECH PROJECT, 2019
** warrior
** File description:
** warrior
*/

#ifndef WARRIOR_HPP_
#define WARRIOR_HPP_

#include <string>
#include <iostream>
#include <iomanip>
#include "Character.hpp"

class Warrior : public Character {
	public:
		Warrior(const std::string &name, int level, const std::string &weapon = "hammer");
		~Warrior();
        int CloseAttack();
        int RangeAttack();

	protected:
	private:
        std::string weaponName;
};

#endif /* !WARRIOR_HPP_ */
