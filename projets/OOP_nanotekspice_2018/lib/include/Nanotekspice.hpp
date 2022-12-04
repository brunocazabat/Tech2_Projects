/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/

#ifndef _NANOTEKSPICE_HPP_
#define _NANOTEKSPICE_HPP_

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
    int const _ac;
    bool _isrunning;
    std::vector<std::pair<std::string, std::string> > _av;
    std::map<std::string, std::function<void(void)> > _cmd;

    void exit(void);
    void display(void);
    void simulate(void);
    void loop(void);
    void dump(void);
    void setInputValue(std::string const& s, size_t const pos) const;

    std::string epurcmd(std::string const& cmd) const;
    
    nts::Circuit *_circuit;
  };
}

void signalLoop(int n);
void doNothing(int n);

#endif /* !_NANOTEKSPICE_HPP_ */
