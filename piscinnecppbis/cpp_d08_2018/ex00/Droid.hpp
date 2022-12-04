/*
** EPITECH PROJECT, 2019
** droid
** File description:
** droid
*/

#ifndef DROID_HPP_
	#define DROID_HPP_

#include <string>
#include <iomanip>
#include <iostream>

class Droid {
	public:
		Droid(std::string serial = "");
        Droid(const Droid &copy);
		~Droid();
        Droid &operator=(Droid &copy);
        bool operator==(const Droid &other);
        bool operator!=(const Droid &other);
        void setId(std::string id);
        void setEnergy(size_t energy);
        void setStatus(std::string *status);
        std::string getId();
        size_t getEnergy();
        size_t getAttack();
        size_t getToughness();
        std::string *getStatus();
        void operator<<(size_t &energy);

	protected:
	private:
        std::string _id;
        size_t _energy;
        const size_t _attack = 25;
        const size_t _toughness = 15;
        std::string *_status;
};

#endif /* !DROID_HPP_ */
