/*
** EPITECH PROJECT, 2019
** h
** File description:
** h
*/

#ifndef AWEAPON_HPP_
#define AWEAPON_HPP_

#include <string>
#include <iostream>

class AWeapon {
  public:
    AWeapon(const std::string &name, int apcost, int damage);
    virtual ~AWeapon();
    const std::string &getName() const;
    int getAPCost() const;
    int getDamage() const;
    virtual void attack() const = 0;

  protected:
    std::string _name;
    int _apCost;
    int _damages;

};

#endif /* !AWEAPON_HPP_ */
