/*
** EPITECH PROJECT, 2019
** character
** File description:
** character
*/

#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include <string>
#include <iostream>
#include "AWeapon.hpp"
#include "AEnemy.hpp"

class Character {
  public:
    Character(const std::string &name);
    virtual ~Character();
    void recoverAP();
    void equip(AWeapon *weapon);
    void attack(AEnemy *enemy);
    const std::string &getName() const;
    int getAP() const;
    const std::string &getWeaponName() const;
    bool isWeapon() const;

  private:
    std::string _name;
    AWeapon *_weapon;
    int _Ap;
};

std::ostream &operator<<(std::ostream &s, const Character &character);

#endif /* !CHARACTER_HPP_ */
