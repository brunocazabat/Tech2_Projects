/*
** EPITECH PROJECT, 2019
** power
** File description:
** power
*/

#ifndef POWERFIST_HPP_
#define POWERFIST_HPP_

#include "AWeapon.hpp"

class PowerFist : public AWeapon {
	public:
		PowerFist();
		~PowerFist();
        void attack() const;

	protected:
	private:
};

#endif /* !POWERFIST_HPP_ */
