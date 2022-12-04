/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#pragma once

#include <iostream>
#include <string>
#include <map>
#include <functional>
#include <utility>
#include <vector>
#include <signal.h>
#include "Circuit.hpp"
#include "IComponent.hpp"

namespace nts
{
  class Nanotekspice
  {
  public:
    static bool Loop;
    static std::string Prompt;
  public:
    Nanotekspice(std::string const& filename, int const ac, char const * const * const av);
    ~Nanotekspice(void);
    void shell(void);
  private:
    int const __ac;
    bool __isrunning;
    std::vector<std::pair<std::string, std::string> > __av;
    std::map<std::string, std::function<void(void)> > __cmd;
    void exit(void);
    void display(void);
    void simulate(void);
    void loop(void);
    void dump(void);
    void setInputval(std::string const& s, size_t const pos) const;
    std::string epurcmd(std::string const& cmd) const;
    nts::Circuit *__circuit;
  };
}

void signalLoop(int n);
void doNothing(int n);
