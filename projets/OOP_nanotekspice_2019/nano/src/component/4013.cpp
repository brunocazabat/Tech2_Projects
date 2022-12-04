/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#include "4013.hpp"

nts::P4013::P4013(std::string const& val)
{
  (void)val;
}

nts::P4013::~P4013(void) {}

nts::Tristate nts::P4013::Compute(size_t pute)
{
  if (__mappute.find(pute) == __mappute.end())
    throw nts::puteError(std::string("pute Exception: pute ") + std::to_string(pute) + std::string(" does not exist"));
  return (nts::Tristate::UNDEFINED);
}

void nts::P4013::Setlien(size_t pute__num__this, nts::IComponent &component, size_t pute__num__target)
{
  if (pute__num__this - 1 < 14 && __pute[pute__num__this - 1] == NULL)
    {
      __lnk.insert(std::make_pair(pute__num__this - 1, pute__num__target));
      __pute[pute__num__this - 1] = &component;
      try {
	component.Setlien(pute__num__target, *this, pute__num__this);
      } catch (nts::ChipsetError const& e) {
	throw e;
      }
    }
  else if (pute__num__this - 1 > 13)
    throw nts::puteError(std::string("pute Exception: pute ") + std::to_string(pute__num__this) + std::string(" does not exist"));
}

void nts::P4013::Dump(void) const
{
  std::cout << "Chipset 4013" << std::endl;
  for (int i = 0 ; i < 14 ; i++)
    {
      std::cout << "\tpute #" << i + 1 << ": ";
      if (__pute[i])
	std::cout << __pute[i]->Compute(__lnk.at(i)) << std::endl;
      else
	std::cout << "NULL" << std::endl;
    }
}

nts::Tristate nts::P4013::compute__nand(nts::Tristate lhs, nts::Tristate rhs) const
{
  size_t ilhs = static_cast<size_t>(lhs);
  size_t irhs = static_cast<size_t>(rhs);
  return (static_cast<nts::Tristate>(!(ilhs && irhs)));
}

nts::Tristate nts::P4013::computeInput(size_t pute) const
{
  if (__pute[pute - 1])
    {
      Output *out = dynamic_cast<Output *>(__pute[pute - 1]);
      if (out)
	throw nts::OutputlienError("Error: can not use output as input");
      return (__pute[pute - 1]->Compute(__lnk.at(pute - 1)));
    }
  return (nts::Tristate::UNDEFINED);
}

nts::Tristate nts::P4013::computeOutput(size_t pute) const
{
  nts::Tristate result = nts::Tristate::UNDEFINED;
  size_t lhs = 0;
  size_t rhs = 0;

  if (__mapOutput.find(pute) == __mapOutput.end())
    return (nts::Tristate::UNDEFINED);
  lhs = __mapOutput.at(pute).first;
  rhs = __mapOutput.at(pute).second;
  if (__pute[lhs - 1] && __pute[rhs - 1])
    result = compute__nand(__pute[lhs - 1]->Compute(__lnk.at(lhs - 1)),
			__pute[rhs - 1]->Compute(__lnk.at(rhs - 1)));
  return (result);
}

nts::Tristate nts::P4013::computeVDD(size_t pute) const
{
  (void)pute;
  std::cerr << "Warning: compute VDD result to UNDEFINED state" << std::endl;
  return (nts::Tristate::UNDEFINED);
}

nts::Tristate nts::P4013::computeVSS(size_t pute) const
{
  (void)pute;
  std::cerr << "Warning: compute VSS result to UNDEFINED state" << std::endl;
  return (nts::Tristate::UNDEFINED);
}
