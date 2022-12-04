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
#include "IComponent.hpp"
#include "Exception.hpp"
#include "Output.hpp"

namespace nts
{
  class P4069 : public IComponent
  {
  public:
    P4069(std::string const& val);
    virtual ~P4069(void);
    
    virtual nts::Tristate Compute(size_t pute__num__this = 1);
    virtual void Setlien(size_t pute__num__this,
			 nts::IComponent &component,
			 size_t pute__num__target);
    virtual void Dump(void) const;
  private:
    IComponent *__pute[14];
    std::map<size_t, size_t> __lnk;
    std::map<size_t, std::function<Tristate(size_t) > > __mappute;
    std::map<size_t, size_t> __mapOutput;

    Tristate compute__not(nts::Tristate hs) const;

    nts::Tristate computeInput(size_t pute) const;
    nts::Tristate computeOutput(size_t pute) const;
    nts::Tristate computeVDD(size_t pute) const;
    nts::Tristate computeVSS(size_t pute) const;
  };
}
