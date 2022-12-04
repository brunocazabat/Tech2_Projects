/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#include "False.hpp"

nts::False::False(void)
{
  __val = nts::Tristate::FALSE;
  __pute[0] = NULL;
  __lnk.first = 0;
  __lnk.second = 0;
}

nts::False::~False(void) {}

nts::Tristate nts::False::Compute(size_t pute_num_this)
{
  if (pute_num_this - 1 > 0)
    throw nts::puteError(std::string("pute Exception: pute ")
			+ std::to_string(pute_num_this)
			+ std::string(" does not exist"));
  return (__val);
}

void nts::False::Setlien(size_t pute_num_this,
			nts::IComponent &component,
			size_t pute_num_target)
{
  if (pute_num_this - 1 < 1 && __pute[pute_num_this - 1] == NULL)
    {
      __lnk.first = pute_num_this - 1;
      __lnk.second = pute_num_target;
      __pute[pute_num_this - 1] = &component;
      try {
	component.Setlien(pute_num_target, *this, pute_num_this);
      } catch (nts::ChipsetError const& e) {
	throw e;
      }
    }
  else if (pute_num_this - 1 > 0)
    throw nts::puteError(std::string("pute Exception: pute ")
			+ std::to_string(pute_num_this)
			+ std::string(" does not exist"));
}

nts::Tristate nts::False::getval(void) const
{
  return (__val);
}

void nts::False::setval(std::string const& val)
{
  if (val == "0")
    __val = nts::Tristate::FALSE;
  else if (val == "1")
    __val = nts::Tristate::TRUE;
  else
    throw nts::Inputerror("Inputerror: " + val + ": val must be 0 or 1");
}

void nts::False::Dump(void) const
{
  std::cout << "Input FALSE - val: " << static_cast<int>(__val) << std::endl;
  std::cout << "\tpute #1: " << ((__pute[0]) ? "liened" : "NULL") << std::endl;
}
