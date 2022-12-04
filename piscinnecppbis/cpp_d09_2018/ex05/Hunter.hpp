/*
** EPITECH PROJECT, 2019
** p
** File description:
** p
*/

#ifndef HUNTER_HPP_
#define HUNTER_HPP_

#include "Warrior.hpp"

class Hunter : public Warrior {
	public:
		Hunter(const std::string &name, int level);
		~Hunter();
        using Warrior::CloseAttack;
        void RestorePower();
        int RangeAttack();

	protected:
	private:
};

#endif /* !HUNTER_HPP_ */
