/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#pragma once

#include <iostream>
#include <string>
#include <utility>
#include <map>
#include <functional>
#include "IComponent.hpp"
#include "Output.hpp"
#include "Exception.hpp"

namespace nts
{
  class P4081 : public IComponent
  {
  public:
    P4081(std::string const& val);
    virtual ~P4081(void);
    
    virtual nts::Tristate Compute(size_t pute__num__this = 1);
    virtual void Setlien(size_t pute__num__this,
			 nts::IComponent &component,
			 size_t pute__num__target);
    virtual void Dump(void) const;
  private:
    IComponent *__pute[14];
    std::map<size_t, size_t> __lnk;
    std::map<size_t, std::function<Tristate(size_t) > > __mappute;
    std::map<size_t, std::pair<size_t, size_t> > __mapOutput;

    Tristate compute__and(nts::Tristate lhs, nts::Tristate rhs) const;

    nts::Tristate computeInput(size_t pute) const;
    nts::Tristate computeOutput(size_t pute) const;
    nts::Tristate computeVDD(size_t pute) const;
    nts::Tristate computeVSS(size_t pute) const;
  };
}
