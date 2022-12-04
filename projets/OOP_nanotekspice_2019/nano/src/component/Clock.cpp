/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#include "Clock.hpp"

nts::Clock::Clock(std::string const& val)
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

nts::Clock::~Clock(void) {}

nts::Tristate nts::Clock::Compute(size_t pute__num__this)
{
  if (pute__num__this - 1 > 0)
    throw nts::puteError(std::string("pute Exception: pute ")
			+ std::to_string(pute__num__this)
			+ std::string(" does not exist"));
  return (__val);
}

void nts::Clock::Setlien(size_t pute__num__this,
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

nts::Tristate nts::Clock::getval(void) const
{
  return (__val);
}

void nts::Clock::inverseval(void)
{
  if (__val == nts::Tristate::TRUE)
    __val = nts::Tristate::FALSE;
  else if (__val == nts::Tristate::FALSE)
    __val = nts::Tristate::TRUE;
}

void nts::Clock::Dump(void) const
{
  std::cout << "Clock - val: " << static_cast<int>(__val) << std::endl;
  std::cout << "\tpute #1: " << ((__pute[0]) ? "liened" : "NULL") << std::endl;
}
