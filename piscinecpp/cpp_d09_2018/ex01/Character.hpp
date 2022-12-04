/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/

#ifndef CHARACTER_HPP_
	#define CHARACTER_HPP_

#include <iostream>
#include <string>

class Character {
	
    public:
		Character(const std::string &name, int level);
		~Character();
        const std::string   &getName() const;
        int                 getLvl() const;
        int                 getPv() const;
        int                 getPower() const;
        int			        CloseAttack();
        int			        RangeAttack();
        void                Heal();
        void                RestorePower();
        void                TakeDamage(int _Damage);
        
        enum    AttackRange
        {
                CLOSE, RANGE
        };
        AttackRange Range;
	
    private:
        std::string	_Name;
        std::string	_Race;
        int		    _Level;
        int		    _Power;
        int		    _Health;
        int		    _Strength;
        int		    _Stamina;
        int		    _Intelligence;
        int		    _Spirit;
        int		    _Agility;
};

#endif /* !CHARACTER_HPP_ */