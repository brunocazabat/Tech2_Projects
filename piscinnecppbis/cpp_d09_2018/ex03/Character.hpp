/*
** EPITECH PROJECT, 2019
** Charac
** File description:
** Charac
*/

#ifndef CHARACTER_HPP_
	#define CHARACTER_HPP_

#include <string>
#include <iostream>
#include <iomanip>

class Character {
	public:
        Character(const std::string &name, int level);
		~Character();
        const std::string &getName() const;
        int getLvl() const;
        int getPv() const;
        int getPower() const;
        void TakeDamage(int damage);
        int CloseAttack();
        int RangeAttack();
        void Heal();
        void RestorePower();
        enum AttackRange {
            CLOSE,
            RANGE
        };
        int Range;

	protected:
        int _stamina;
        int _spirit;
        int _agility;
        int _intelligence;
        int _strength;
        std::string _name;
        int _level;
        int _pv;
        int _energy;
        std::string _class;
        std::string _race;

	private:
};

#endif /* !CHARACTER_HPP_ */
