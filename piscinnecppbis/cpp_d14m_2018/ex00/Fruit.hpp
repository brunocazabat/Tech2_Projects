/*
** EPITECH PROJECT, 2019
** fruit
** File description:
** fruit
*/

#ifndef FRUIT_HPP_
#define FRUIT_HPP_

#include <string>

class Fruit {
	public:
		Fruit(const int vitamins, const std::string &name);
		~Fruit();
        int getVitamins() const;
        std::string getName() const;

	protected:
        std::string _name;
        int _vitamins;
        
	private:
};

#endif /* !FRUIT_HPP_ */
