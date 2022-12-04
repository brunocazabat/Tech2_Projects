/*
** EPITECH PROJECT, 2019
** Stimpak
** File description:
** Stimpak
*/

#ifndef SKAT_HPP_
#define SKAT_HPP_

#include <string>
#include <iostream>

class Skat
{
  public:
    Skat(const std::string &name = "bob", int stimPaks = 15);
    Skat(const int &stimPaks);
    ~Skat();
    int &stimPaks();
    int &stimPaks(int stimpaks);
    const std ::string &name();
    void shareStimPaks(int number, int &stock);
    void addStimPaks(unsigned int number);
    void useStimPaks();
    void status();

  private:
    std::string _name;
    int _stimPaks;
};

#endif /* !SKAT_HPP_ */