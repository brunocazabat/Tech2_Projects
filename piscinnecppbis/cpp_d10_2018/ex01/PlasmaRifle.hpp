/*
** EPITECH PROJECT, 2019
** rifle
** File description:
** rifle
*/

#ifndef PLASMARIFLE_HPP_
#define PLASMARIFLE_HPP_

#include "AWeapon.hpp"

class PlasmaRifle : public AWeapon {
	public:
		PlasmaRifle();
		~PlasmaRifle();
        void attack() const;

	protected:
	private:
};

#endif /* !PLASMARIFLE_HPP_ */
