/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/

#ifndef _INPUT_HPP_
#define _INPUT_HPP_

#include <iostream>
#include <string>
#include <utility>
#include "IComponent.hpp"
#include "Exception.hpp"

namespace nts
{
  class Input : public IComponent
  {
  public:
    Input(std::string const& value);
    virtual ~Input(void);
    virtual nts::Tristate Compute(size_t pin_num_this = 1);
    virtual void SetLink(size_t pin_num_this,
			 nts::IComponent &component,
			 size_t pin_num_target);
    virtual void Dump(void) const;
    nts::Tristate getValue(void) const;
    void setValue(std::string const& value);
  private:
    nts::Tristate _value;
    IComponent *_pin[1];
    std::pair<size_t, size_t> _lnk;
  };
}

#endif /* !_INPUT_HPP_ */
