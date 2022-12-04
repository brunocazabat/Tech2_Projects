/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/

#include "False.hpp"

nts::False::False(void)
{
  _value = nts::Tristate::FALSE;
  _pin[0] = NULL;
  _lnk.first = 0;
  _lnk.second = 0;
}

nts::False::~False(void)
{
  
}

nts::Tristate nts::False::Compute(size_t pin_num_this)
{
  if (pin_num_this - 1 > 0)
    throw nts::PinError(std::string("Pin Exception: Pin ")
			+ std::to_string(pin_num_this)
			+ std::string(" does not exist"));
  return (_value);
}

void nts::False::SetLink(size_t pin_num_this,
			nts::IComponent &component,
			size_t pin_num_target)
{
  if (pin_num_this - 1 < 1 && _pin[pin_num_this - 1] == NULL)
    {
      _lnk.first = pin_num_this - 1;
      _lnk.second = pin_num_target;
      _pin[pin_num_this - 1] = &component;
      try {
	component.SetLink(pin_num_target, *this, pin_num_this);
      } catch (nts::ChipsetError const& e) {
	throw e;
      }
    }
  else if (pin_num_this - 1 > 0)
    throw nts::PinError(std::string("Pin Exception: Pin ")
			+ std::to_string(pin_num_this)
			+ std::string(" does not exist"));
}

nts::Tristate nts::False::getValue(void) const
{
  return (_value);
}

void nts::False::setValue(std::string const& value)
{
  if (value == "0")
    _value = nts::Tristate::FALSE;
  else if (value == "1")
    _value = nts::Tristate::TRUE;
  else
    throw nts::InputError("InputError: " + value + ": value must be 0 or 1");
}

void nts::False::Dump(void) const
{
  std::cout << "Input FALSE - value: " << static_cast<int>(_value) << std::endl;
  std::cout << "\tpin #1: " << ((_pin[0]) ? "linked" : "NULL") << std::endl;
}
