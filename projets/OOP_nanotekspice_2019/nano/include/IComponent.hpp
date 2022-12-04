/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#pragma once

namespace nts
{
  enum Tristate
    {
      UNDEFINED = (-true),
      TRUE = true,
      FALSE = false
    };

  class IComponent
  {
  public:
    virtual ~IComponent(void) {}
    virtual nts::Tristate Compute(size_t pute__num__this = 1) = 0;
    virtual void Setlien(size_t pute__num__this, nts::IComponent &component, size_t pute__num__target) = 0;
    virtual void Dump(void) const = 0;
  };
}
