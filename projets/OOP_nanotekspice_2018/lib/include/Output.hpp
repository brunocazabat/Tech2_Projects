/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/

#ifndef _OUTPUT_HPP_
#define _OUTPUT_HPP_

#include <iostream>
#include <string>
#include <utility>
#include "IComponent.hpp"
#include "Exception.hpp"

namespace nts
{
  class Output : public IComponent
  {
  public:
    Output(void);
    virtual ~Output(void);
    virtual nts::Tristate Compute(size_t pin_num_this = 1);
    virtual void SetLink(size_t pin_num_this,
			 nts::IComponent &component,
			 size_t pin_num_target);
    virtual void Dump(void) const;
    nts::Tristate getValue(void) const;
  private:
    nts::Tristate _value;
    IComponent *_pin[1];
    std::pair<size_t, size_t> _lnk;
  };
}

#endif /* !_INPUT_HPP_ */
