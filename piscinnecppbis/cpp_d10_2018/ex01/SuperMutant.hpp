/*
** EPITECH PROJECT, 2019
** e
** File description:
** e
*/

#ifndef SUPERMUTANT_HPP_
#define SUPERMUTANT_HPP_

#include "AEnemy.hpp"
#include <string>
#include "iostream"

class SuperMutant : public AEnemy {
	public:
		SuperMutant();
		~SuperMutant();
        void takeDamage(int damage);

	protected:
	private:
};

#endif /* !SUPERMUTANT_HPP_ */
