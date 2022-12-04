/*
** EPITECH PROJECT, 2019
** hand
** File description:
** hand
*/

#ifndef LITTLEHAND_HPP_
#define LITTLEHAND_HPP_

#include "FruitBox.hpp"

class LittleHand {
	public:
		LittleHand() {};
		~LittleHand() {};
        static void sortFruitBox(FruitBox &unsorted, FruitBox &lemons, FruitBox &bananas, FruitBox &limes);

	protected:
	private:
};

#endif /* !LITTLEHAND_HPP_ */
