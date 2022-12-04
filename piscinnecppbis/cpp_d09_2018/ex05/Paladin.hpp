/*
** EPITECH PROJECT, 2019
** pala
** File description:
** pala
*/

#ifndef PALADIN_HPP_
#define PALADIN_HPP_

#include <string>
#include <iostream>
#include "Priest.hpp"
#include "Warrior.hpp"
#include "Character.hpp"

class Paladin : public Warrior, public Priest {
	public:
		Paladin(const std::string &name, int level);
		~Paladin();
        int Intercept();
        using Warrior::CloseAttack;
        using Warrior::RestorePower;
        using Priest::RangeAttack;
        using Priest::Heal;

	protected:
	private:
};

#endif /* !PALADIN_HPP_ */
