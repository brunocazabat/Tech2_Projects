/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/

#ifndef _C4008_HPP_
#define _C4008_HPP_

#include <iostream>
#include <string>
#include <utility>
#include <map>
#include <functional>
#include "IComponent.hpp"
#include "Exception.hpp"
#include "Output.hpp"

namespace nts
{
  class C4008 : public IComponent
  {
  public:
    C4008(std::string const& value);
    virtual ~C4008(void);
    
    virtual nts::Tristate Compute(size_t pin_num_this = 1);
    virtual void SetLink(size_t pin_num_this,
			 nts::IComponent &component,
			 size_t pin_num_target);
    virtual void Dump(void) const;
  private:
    IComponent *_pin[16];
    std::map<size_t, size_t> _lnk;
    std::map<size_t, std::function<Tristate(size_t) > > _mapPin;
    std::map<size_t, std::pair<size_t, size_t> > _mapOutput;

    Tristate compute_add(nts::Tristate lhs, nts::Tristate rhs,
			 nts::Tristate &carry) const;
    
    nts::Tristate computeInput(size_t pin) const;
    nts::Tristate computeOutput(size_t pin) const;
    nts::Tristate computeCarryOut(size_t pin) const;
    nts::Tristate computeVDD(size_t pin) const;
    nts::Tristate computeVSS(size_t pin) const;
  };
}

#endif /* !_C4001_HPP_ */
