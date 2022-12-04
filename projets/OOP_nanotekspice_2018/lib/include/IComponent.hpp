/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/

#ifndef _ICOMPONENT_HPP_
#define _ICOMPONENT_HPP_

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
    virtual nts::Tristate Compute(size_t pin_num_this = 1) = 0;
    virtual void SetLink(size_t pin_num_this, nts::IComponent &component, size_t pin_num_target) = 0;
    virtual void Dump(void) const = 0;
  };
}

#endif /* !_ICOMPONENT_HPP_ */
