/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#include "Output.hpp"

nts::Output::Output(void)
{
  __val = nts::Tristate::UNDEFINED;
  __pute[0] = NULL;
  __lnk.first = 0;
  __lnk.second = 0;
}

nts::Output::~Output(void) {}

nts::Tristate nts::Output::Compute(size_t pute_num_this)
{
  if (pute_num_this - 1 > 0)
    throw nts::puteError(std::string("pute Exception: pute ")
			+ std::to_string(pute_num_this)
			+ std::string(" does not exist"));
  if (__pute[pute_num_this - 1] == NULL)
    throw nts::OutputlienError("Error: output is not liened");
  __val = __pute[pute_num_this - 1]->Compute(__lnk.second);
  return (__val);
}

void nts::Output::Setlien(size_t pute_num_this,
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

nts::Tristate nts::Output::getval(void) const
{
  return (__val);
}

void nts::Output::Dump(void) const
{
  std::cout << "Output - val: " << static_cast<int>(__val) << std::endl;
  std::cout << "\tpute #1: " << ((__pute[0]) ? "liened" : "NULL") << std::endl;
}
