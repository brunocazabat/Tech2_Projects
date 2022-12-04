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
#include "IComponent.hpp"
#include "Exception.hpp"

namespace nts
{
  class True : public IComponent
  {
  public:
    True(void);
    virtual ~True(void);
    virtual nts::Tristate Compute(size_t pute__num__this = 1);
    virtual void Setlien(size_t pute__num__this, nts::IComponent &component, size_t pute__num__target);
    virtual void Dump(void) const;
    nts::Tristate getval(void) const;
    void setval(std::string const& val);
  private:
    nts::Tristate __val;
    IComponent *__pute[1];
    std::pair<size_t, size_t> __lnk;
  };
}
