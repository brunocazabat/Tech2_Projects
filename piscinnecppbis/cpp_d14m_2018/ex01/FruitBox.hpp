/*
** EPITECH PROJECT, 2019
** fruitbox
** File description:
** fruitbox
*/

#ifndef FRUITBOX_HPP_
#define FRUITBOX_HPP_

#include "Fruit.hpp"
#include "FruitNode.hpp"

class FruitBox {
	public:
		FruitBox(const int size);
		~FruitBox();
        int nbFruits() const;
        bool putFruit(Fruit *f);
        Fruit *pickFruit();
        FruitNode *head();

	protected:
	private:
        FruitBox &operator=(const FruitBox &box);
		FruitBox(const FruitBox &box);
        int _nbFruits;
        int _size;
        FruitNode *_head;
};

#endif /* !FRUITBOX_HPP_ */
