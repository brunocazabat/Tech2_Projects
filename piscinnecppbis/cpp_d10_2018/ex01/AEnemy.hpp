/*
** EPITECH PROJECT, 2019
** enemy
** File description:
** enemy
*/

#ifndef AENEMY_HPP_
#define AENEMY_HPP_

#include <string>

class AEnemy
{
  public:
    AEnemy(int hp, const std::string &type);
    virtual ~AEnemy();
    virtual void takeDamage(int damage);
    const std::string &getType() const;
    int getHP() const;

  protected:
    int _hp;
    std::string _type;
};

#endif /* !AENEMY_HPP_ */
