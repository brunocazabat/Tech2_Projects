/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/

#include "True.hpp"

nts::True::True(void)
{
  _value = nts::Tristate::TRUE;
  _pin[0] = NULL;
  _lnk.first = 0;
  _lnk.second = 0;
}

nts::True::~True(void)
{
  
}

nts::Tristate nts::True::Compute(size_t pin_num_this)
{
  if (pin_num_this - 1 > 0)
    throw nts::PinError(std::string("Pin Exception: Pin ")
			+ std::to_string(pin_num_this)
			+ std::string(" does not exist"));
  return (_value);
}

void nts::True::SetLink(size_t pin_num_this,
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

nts::Tristate nts::True::getValue(void) const
{
  return (_value);
}

void nts::True::setValue(std::string const& value)
{
  if (value == "0")
    _value = nts::Tristate::FALSE;
  else if (value == "1")
    _value = nts::Tristate::TRUE;
  else
    throw nts::InputError("InputError: " + value + ": value must be 0 or 1");
}

void nts::True::Dump(void) const
{
  std::cout << "Input TRUE - value: " << static_cast<int>(_value) << std::endl;
  std::cout << "\tpin #1: " << ((_pin[0]) ? "linked" : "NULL") << std::endl;
}
