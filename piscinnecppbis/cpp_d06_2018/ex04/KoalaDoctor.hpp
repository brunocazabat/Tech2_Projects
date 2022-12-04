/*
** EPITECH PROJECT, 2019
** KoalaDoctor
** File description:
** KoalaDoctor
*/

#ifndef KOALADOCTOR_HPP_
#define KOALADOCTOR_HPP_

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "SickKoala.hpp"
#include "KoalaNurse.hpp"

class KoalaDoctor
{
  public:
    KoalaDoctor(std::string name);
    ~KoalaDoctor();
    void diagnose(SickKoala *koala);
    void timeCheck();
  private:
    std::string _name;
    bool _work;
};

#endif /* !KOALADOCTOR_HPP_ */
