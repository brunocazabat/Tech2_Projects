/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#include "4069.hpp"

nts::P4069::P4069(std::string const& val)
{
  (void)val;
  for (int i = 0 ; i < 14 ; i++)
    __pute[i] = NULL;

  // pute Input
  __mappute[1] = std::bind(&nts::P4069::computeInput, this, std::placeholders::_1);
  __mappute[3] = std::bind(&nts::P4069::computeInput, this, std::placeholders::_1);
  __mappute[5] = std::bind(&nts::P4069::computeInput, this, std::placeholders::_1);
  __mappute[9] = std::bind(&nts::P4069::computeInput, this, std::placeholders::_1);
  __mappute[11] = std::bind(&nts::P4069::computeInput, this, std::placeholders::_1);
  __mappute[13] = std::bind(&nts::P4069::computeInput, this, std::placeholders::_1);
  
  // pute Output
  __mappute[2] = std::bind(&nts::P4069::computeOutput, this, std::placeholders::_1);
  __mappute[4] = std::bind(&nts::P4069::computeOutput, this, std::placeholders::_1);
  __mappute[6] = std::bind(&nts::P4069::computeOutput, this, std::placeholders::_1);
  __mappute[8] = std::bind(&nts::P4069::computeOutput, this, std::placeholders::_1);
  __mappute[10] = std::bind(&nts::P4069::computeOutput, this, std::placeholders::_1);
  __mappute[12] = std::bind(&nts::P4069::computeOutput, this, std::placeholders::_1);

  // VDD
  __mappute[14] = std::bind(&nts::P4069::computeVDD, this, std::placeholders::_1);
  
  // VSS
  __mappute[7] = std::bind(&nts::P4069::computeVSS, this, std::placeholders::_1);

  // Output-Input lien
  __mapOutput[2] = 1;
  __mapOutput[4] = 3;
  __mapOutput[6] = 5;
  __mapOutput[8] = 9;
  __mapOutput[10] = 11;
  __mapOutput[12] = 13;
}

nts::P4069::~P4069(void) {}

nts::Tristate nts::P4069::Compute(size_t pute)
{
  if (__mappute.find(pute) == __mappute.end())
    throw nts::puteError(std::string("pute Exception: pute ")
			+ std::to_string(pute)
			+ std::string(" does not exist"));
  try {
    return (__mappute[pute](pute));
  } catch (nts::NtsError const& e) {
    throw e;
  }
  return (nts::Tristate::UNDEFINED);
}

void nts::P4069::Setlien(size_t pute__num__this,
			 nts::IComponent &component,
			 size_t pute__num__target)
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
    throw nts::puteError(std::string("pute Exception: pute ")
			+ std::to_string(pute__num__this)
			+ std::string(" does not exist"));
}

void nts::P4069::Dump(void) const
{
  std::cout << "Chipset 4069" << std::endl;
  for (int i = 0 ; i < 14 ; i++)
    {
      std::cout << "\tpute #" << i + 1 << ": ";
      if (__pute[i])
	std::cout << __pute[i]->Compute(__lnk.at(i)) << std::endl;
      else
	std::cout << "NULL" << std::endl;
    }
}

nts::Tristate nts::P4069::compute__not(nts::Tristate hs) const
{
  if (hs != nts::Tristate::UNDEFINED)
    return (static_cast<nts::Tristate>(!static_cast<int>(hs)));
  return hs;
}

nts::Tristate nts::P4069::computeInput(size_t pute) const
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

nts::Tristate nts::P4069::computeOutput(size_t pute) const
{
  nts::Tristate result = nts::Tristate::UNDEFINED;
  size_t lhs = 0;

  if (__mapOutput.find(pute) == __mapOutput.end())
    return (nts::Tristate::UNDEFINED);
  lhs = __mapOutput.at(pute);
  if (__pute[lhs - 1])
    result = compute__not(__pute[lhs - 1]->Compute(__lnk.at(lhs - 1)));
  return (result);
}

nts::Tristate nts::P4069::computeVDD(size_t pute) const
{
  (void)pute;
  std::cerr << "Warning: compute VDD result to UNDEFINED state" << std::endl;
  return (nts::Tristate::UNDEFINED);
}

nts::Tristate nts::P4069::computeVSS(size_t pute) const
{
  (void)pute;
  std::cerr << "Warning: compute VSS result to UNDEFINED state" << std::endl;
  return (nts::Tristate::UNDEFINED);
}
