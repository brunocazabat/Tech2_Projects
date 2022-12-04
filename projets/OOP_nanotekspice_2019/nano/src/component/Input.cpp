/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#include "Input.hpp"

nts::Input::Input(std::string const& val)
{
  if (val == "0")
    __val = nts::Tristate::FALSE;
  else if (val == "1")
    __val = nts::Tristate::TRUE;
  else
    __val = nts::Tristate::UNDEFINED;
  __pute[0] = NULL;
  __lnk.first = 0;
  __lnk.second = 0;
}

nts::Input::~Input(void) {}

nts::Tristate nts::Input::Compute(size_t pute__num__this)
{
  if (pute__num__this - 1 > 0)
    throw nts::puteError(std::string("pute Exception: pute ")
			+ std::to_string(pute__num__this)
			+ std::string(" does not exist"));
  return (__val);
}

void nts::Input::Setlien(size_t pute__num__this,
		    nts::IComponent &component,
		    size_t pute__num__target)
{
  if (pute__num__this - 1 < 1 && __pute[pute__num__this - 1] == NULL)
    {
      __lnk.first = pute__num__this - 1;
      __lnk.second = pute__num__target;
      __pute[pute__num__this - 1] = &component;
      try {
	component.Setlien(pute__num__target, *this, pute__num__this);
      } catch (nts::ChipsetError const& e) {
	throw e;
      }
    }
  else if (pute__num__this - 1 > 0)
    throw nts::puteError(std::string("pute Exception: pute ")
			+ std::to_string(pute__num__this)
			+ std::string(" does not exist"));
}

nts::Tristate nts::Input::getval(void) const
{
  return (__val);
}

void nts::Input::setval(std::string const& val)
{
  if (val == "0")
    __val = nts::Tristate::FALSE;
  else if (val == "1")
    __val = nts::Tristate::TRUE;
  else
    throw nts::Inputerror("Inputerror: " + val + ": val must be 0 or 1");
}

void nts::Input::Dump(void) const
{
  std::cout << "Input - val: " << static_cast<int>(__val) << std::endl;
  std::cout << "\tpute #1: " << ((__pute[0]) ? "liened" : "NULL") << std::endl;
}
