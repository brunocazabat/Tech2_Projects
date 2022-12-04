/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/

#include "C4069.hpp"

nts::C4069::C4069(std::string const& value)
{
  (void)value;
  for (int i = 0 ; i < 14 ; i++)
    _pin[i] = NULL;

  // Pin Input
  _mapPin[1] = std::bind(&nts::C4069::computeInput, this, std::placeholders::_1);
  _mapPin[3] = std::bind(&nts::C4069::computeInput, this, std::placeholders::_1);
  _mapPin[5] = std::bind(&nts::C4069::computeInput, this, std::placeholders::_1);
  _mapPin[9] = std::bind(&nts::C4069::computeInput, this, std::placeholders::_1);
  _mapPin[11] = std::bind(&nts::C4069::computeInput, this, std::placeholders::_1);
  _mapPin[13] = std::bind(&nts::C4069::computeInput, this, std::placeholders::_1);
  
  // Pin Output
  _mapPin[2] = std::bind(&nts::C4069::computeOutput, this, std::placeholders::_1);
  _mapPin[4] = std::bind(&nts::C4069::computeOutput, this, std::placeholders::_1);
  _mapPin[6] = std::bind(&nts::C4069::computeOutput, this, std::placeholders::_1);
  _mapPin[8] = std::bind(&nts::C4069::computeOutput, this, std::placeholders::_1);
  _mapPin[10] = std::bind(&nts::C4069::computeOutput, this, std::placeholders::_1);
  _mapPin[12] = std::bind(&nts::C4069::computeOutput, this, std::placeholders::_1);

  // VDD
  _mapPin[14] = std::bind(&nts::C4069::computeVDD, this, std::placeholders::_1);
  
  // VSS
  _mapPin[7] = std::bind(&nts::C4069::computeVSS, this, std::placeholders::_1);

  // Output-Input link
  _mapOutput[2] = 1;
  _mapOutput[4] = 3;
  _mapOutput[6] = 5;
  _mapOutput[8] = 9;
  _mapOutput[10] = 11;
  _mapOutput[12] = 13;
}

nts::C4069::~C4069(void)
{
  
}

nts::Tristate nts::C4069::Compute(size_t pin)
{
  if (_mapPin.find(pin) == _mapPin.end())
    throw nts::PinError(std::string("Pin Exception: Pin ")
			+ std::to_string(pin)
			+ std::string(" does not exist"));
  try {
    return (_mapPin[pin](pin));
  } catch (nts::NtsError const& e) {
    throw e;
  }
  return (nts::Tristate::UNDEFINED);
}

void nts::C4069::SetLink(size_t pin_num_this,
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

void nts::C4069::Dump(void) const
{
  std::cout << "Chipset 4069" << std::endl;
  for (int i = 0 ; i < 14 ; i++)
    {
      std::cout << "\tpin #" << i + 1 << ": ";
      if (_pin[i])
	std::cout << _pin[i]->Compute(_lnk.at(i)) << std::endl;
      else
	std::cout << "NULL" << std::endl;
    }
}

nts::Tristate nts::C4069::compute_not(nts::Tristate hs) const
{
  if (hs != nts::Tristate::UNDEFINED)
    return (static_cast<nts::Tristate>(!static_cast<int>(hs)));
  return hs;
}

nts::Tristate nts::C4069::computeInput(size_t pin) const
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

nts::Tristate nts::C4069::computeOutput(size_t pin) const
{
  nts::Tristate result = nts::Tristate::UNDEFINED;
  size_t lhs = 0;

  if (_mapOutput.find(pin) == _mapOutput.end())
    return (nts::Tristate::UNDEFINED);
  lhs = _mapOutput.at(pin);
  if (_pin[lhs - 1])
    result = compute_not(_pin[lhs - 1]->Compute(_lnk.at(lhs - 1)));
  return (result);
}

nts::Tristate nts::C4069::computeVDD(size_t pin) const
{
  (void)pin;
  std::cerr << "Warning: compute VDD result to UNDEFINED state" << std::endl;
  return (nts::Tristate::UNDEFINED);
}

nts::Tristate nts::C4069::computeVSS(size_t pin) const
{
  (void)pin;
  std::cerr << "Warning: compute VSS result to UNDEFINED state" << std::endl;
  return (nts::Tristate::UNDEFINED);
}
