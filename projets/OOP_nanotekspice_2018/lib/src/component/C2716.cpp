/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/

#include "C2716.hpp"

nts::C2716::C2716(std::string const& value)
{
  (void)value;
}

nts::C2716::~C2716(void)
{
}

nts::Tristate nts::C2716::Compute(size_t pin)
{
  if (_mapPin.find(pin) == _mapPin.end())
    throw nts::PinError(std::string("Pin Exception: Pin ")
			+ std::to_string(pin)
			+ std::string(" does not exist"));
  return (nts::Tristate::UNDEFINED);
}

void nts::C2716::SetLink(size_t pin_num_this,
			 nts::IComponent &component,
			 size_t pin_num_target)
{
  if (pin_num_this - 1 < 14 && _pin[pin_num_this - 1] == NULL)
    {
      _lnk.insert(std::make_pair(pin_num_this - 1, pin_num_target));
      _pin[pin_num_this - 1] = &component;
      try {
	component.SetLink(pin_num_target, *this, pin_num_this);
      } catch (nts::ChipsetError const& e) {
	throw e;
      }
    }
  else if (pin_num_this - 1 > 13)
    throw nts::PinError(std::string("Pin Exception: Pin ")
			+ std::to_string(pin_num_this)
			+ std::string(" does not exist"));
}

void nts::C2716::Dump(void) const
{
  std::cout << "Chipset 2716" << std::endl;
  for (int i = 0 ; i < 14 ; i++)
    {
      std::cout << "\tpin #" << i + 1 << ": ";
      if (_pin[i])
	std::cout << _pin[i]->Compute(_lnk.at(i)) << std::endl;
      else
	std::cout << "NULL" << std::endl;
    }
}

nts::Tristate nts::C2716::compute_nand(nts::Tristate lhs, nts::Tristate rhs) const
{
  size_t ilhs = static_cast<size_t>(lhs);
  size_t irhs = static_cast<size_t>(rhs);
  return (static_cast<nts::Tristate>(!(ilhs && irhs)));
}

nts::Tristate nts::C2716::computeInput(size_t pin) const
{
  if (_pin[pin - 1])
    {
      Output *out = dynamic_cast<Output *>(_pin[pin - 1]);
      if (out)
	throw nts::OutputLinkError("Error: can not use output as input");
      return (_pin[pin - 1]->Compute(_lnk.at(pin - 1)));
    }
  return (nts::Tristate::UNDEFINED);
}

nts::Tristate nts::C2716::computeOutput(size_t pin) const
{
  nts::Tristate result = nts::Tristate::UNDEFINED;
  size_t lhs = 0;
  size_t rhs = 0;

  if (_mapOutput.find(pin) == _mapOutput.end())
    return (nts::Tristate::UNDEFINED);
  lhs = _mapOutput.at(pin).first;
  rhs = _mapOutput.at(pin).second;
  if (_pin[lhs - 1] && _pin[rhs - 1])
    result = compute_nand(_pin[lhs - 1]->Compute(_lnk.at(lhs - 1)),
			_pin[rhs - 1]->Compute(_lnk.at(rhs - 1)));
  return (result);
}

nts::Tristate nts::C2716::computeVDD(size_t pin) const
{
  (void)pin;
  std::cerr << "Warning: compute VDD result to UNDEFINED state" << std::endl;
  return (nts::Tristate::UNDEFINED);
}

nts::Tristate nts::C2716::computeVSS(size_t pin) const
{
  (void)pin;
  std::cerr << "Warning: compute VSS result to UNDEFINED state" << std::endl;
  return (nts::Tristate::UNDEFINED);
}
