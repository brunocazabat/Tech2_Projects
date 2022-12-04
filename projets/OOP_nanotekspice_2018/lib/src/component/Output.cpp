/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/

#include "Output.hpp"

nts::Output::Output(void)
{
  _value = nts::Tristate::UNDEFINED;
  _pin[0] = NULL;
  _lnk.first = 0;
  _lnk.second = 0;
}

nts::Output::~Output(void)
{

}

nts::Tristate nts::Output::Compute(size_t pin_num_this)
{
  if (pin_num_this - 1 > 0)
    throw nts::PinError(std::string("Pin Exception: Pin ")
			+ std::to_string(pin_num_this)
			+ std::string(" does not exist"));
  if (_pin[pin_num_this - 1] == NULL)
    throw nts::OutputLinkError("Error: output is not linked");
  _value = _pin[pin_num_this - 1]->Compute(_lnk.second);
  return (_value);
}

void nts::Output::SetLink(size_t pin_num_this,
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

nts::Tristate nts::Output::getValue(void) const
{
  return (_value);
}

void nts::Output::Dump(void) const
{
  std::cout << "Output - value: " << static_cast<int>(_value) << std::endl;
  std::cout << "\tpin #1: " << ((_pin[0]) ? "linked" : "NULL") << std::endl;
}
