/*
** EPITECH PROJECT, 2019
** KoalaNurse
** File description:
** KoalaNurse
*/

#ifndef KOALANURSE_HPP_
#define KOALANURSE_HPP_

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "SickKoala.hpp"

class KoalaNurse
{
  public:
    KoalaNurse(int id);
    ~KoalaNurse();
    void giveDrug(std::string drug, SickKoala *koala);
    std::string readReport(std::string filename);
    void timeCheck();

  private:
    int _id;
    bool _work;
};

#endif /* !KOALANURSE_HPP_ */
