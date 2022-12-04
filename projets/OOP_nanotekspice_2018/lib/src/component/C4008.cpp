/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/

#include "C4008.hpp"

nts::C4008::C4008(std::string const& value)
{
  (void)value;
  for (int i = 0 ; i < 16 ; i++)
    _pin[i] = NULL;

  // 4 * 2 bits to add
  _mapPin[1] = std::bind(&nts::C4008::computeInput, this, std::placeholders::_1);
  _mapPin[2] = std::bind(&nts::C4008::computeInput, this, std::placeholders::_1);
  _mapPin[3] = std::bind(&nts::C4008::computeInput, this, std::placeholders::_1);
  _mapPin[4] = std::bind(&nts::C4008::computeInput, this, std::placeholders::_1);
  _mapPin[5] = std::bind(&nts::C4008::computeInput, this, std::placeholders::_1);
  _mapPin[6] = std::bind(&nts::C4008::computeInput, this, std::placeholders::_1);
  _mapPin[7] = std::bind(&nts::C4008::computeInput, this, std::placeholders::_1);
  _mapPin[15] = std::bind(&nts::C4008::computeInput, this, std::placeholders::_1);

  // carry in
  _mapPin[9] = std::bind(&nts::C4008::computeInput, this, std::placeholders::_1);

  // out
  _mapPin[10] = std::bind(&nts::C4008::computeOutput, this, std::placeholders::_1);
  _mapPin[11] = std::bind(&nts::C4008::computeOutput, this, std::placeholders::_1);
  _mapPin[12] = std::bind(&nts::C4008::computeOutput, this, std::placeholders::_1);
  _mapPin[13] = std::bind(&nts::C4008::computeOutput, this, std::placeholders::_1);

  // carry out
  _mapPin[14] = std::bind(&nts::C4008::computeCarryOut, this, std::placeholders::_1);

  // VDD
  _mapPin[16] = std::bind(&nts::C4008::computeVDD, this, std::placeholders::_1);

  // VSS
  _mapPin[8] = std::bind(&nts::C4008::computeVSS, this, std::placeholders::_1);

  _mapOutput[10] = std::make_pair(6, 7);
  _mapOutput[11] = std::make_pair(4, 5);
  _mapOutput[12] = std::make_pair(2, 3);
  _mapOutput[13] = std::make_pair(1, 15);
}

nts::C4008::~C4008(void)
{
  
}

nts::Tristate nts::C4008::Compute(size_t pin)
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

void nts::C4008::SetLink(size_t pin_num_this,
			 nts::IComponent &component,
			 size_t pin_num_target)
{
  if (pin_num_this - 1 < 16 && _pin[pin_num_this - 1] == NULL)
    {
      _lnk.insert(std::make_pair(pin_num_this - 1, pin_num_target));
      _pin[pin_num_this - 1] = &component;
      try {
	component.SetLink(pin_num_target, *this, pin_num_this);
      } catch (nts::ChipsetError const& e) {
	throw e;
      }
    }
  else if (pin_num_this - 1 > 15)
    throw nts::PinError(std::string("Pin Exception: Pin ")
			+ std::to_string(pin_num_this)
			+ std::string(" does not exist"));
}

void nts::C4008::Dump(void) const
{
  std::cout << "Chipset 4008" << std::endl;
  for (int i = 0 ; i < 16 ; i++)
    {
      std::cout << "\tpin #" << i + 1 << ": ";
      if (_pin[i])
	std::cout << _pin[i]->Compute(_lnk.at(i)) << std::endl;
      else
	std::cout << "NULL" << std::endl;
    }
}

nts::Tristate nts::C4008::compute_add(nts::Tristate lhs, nts::Tristate rhs,
				      nts::Tristate &carry) const
{
  char result = ((char)lhs) + ((char)rhs) + ((char)carry);
  carry = static_cast<nts::Tristate>(result >> 1);
  return (static_cast<nts::Tristate>(result & 1));
}

nts::Tristate nts::C4008::computeInput(size_t pin) const
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

nts::Tristate nts::C4008::computeOutput(size_t pin) const
{
  nts::Tristate result = nts::Tristate::UNDEFINED;
  nts::Tristate carry = nts::Tristate::FALSE;
  size_t lhs = 0;
  size_t rhs = 0;

  if (_mapOutput.find(pin) == _mapOutput.end())
    return (nts::Tristate::UNDEFINED);
  if (_pin[8])
    carry = _pin[8]->Compute(_lnk.at(8));
  for (size_t i = 10 ; i <= pin ; i++)
    if (_mapOutput.find(i) != _mapOutput.end())
      {
	lhs = _mapOutput.at(i).first;
	rhs = _mapOutput.at(i).second;
	if (_pin[lhs - 1] && _pin[rhs - 1])
	  result = compute_add(_pin[lhs - 1]->Compute(_lnk.at(lhs - 1)),
			       _pin[rhs - 1]->Compute(_lnk.at(rhs - 1)),
			       carry);
      }
  return (result);
}

nts::Tristate nts::C4008::computeCarryOut(size_t pin) const
{
  nts::Tristate carry = nts::Tristate::FALSE;
  size_t lhs = 0;
  size_t rhs = 0;

  if (_pin[8])
    carry = _pin[8]->Compute(_lnk.at(8));
  for (size_t i = 10 ; i < pin ; i++)
    if (_mapOutput.find(i) != _mapOutput.end())
      {
	lhs = _mapOutput.at(i).first;
	rhs = _mapOutput.at(i).second;
	if (_pin[lhs - 1] && _pin[rhs - 1])
	  compute_add(_pin[lhs - 1]->Compute(_lnk.at(lhs - 1)),
		      _pin[rhs - 1]->Compute(_lnk.at(rhs - 1)),
		      carry);
      }
  return (carry);
}

nts::Tristate nts::C4008::computeVDD(size_t pin) const
{
  (void)pin;
  std::cerr << "Warning: compute VDD result to UNDEFINED state" << std::endl;
  return (nts::Tristate::UNDEFINED);
}

nts::Tristate nts::C4008::computeVSS(size_t pin) const
{
  (void)pin;
  std::cerr << "Warning: compute VSS result to UNDEFINED state" << std::endl;
  return (nts::Tristate::UNDEFINED);
}
