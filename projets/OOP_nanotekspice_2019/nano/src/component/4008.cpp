/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#include "4008.hpp"

nts::P4008::P4008(std::string const& val)
{
  (void)val;
  for (int i = 0 ; i < 16 ; i++)
    __pute[i] = NULL;

  // 4 * 2 bits to add
  __mappute[1] = std::bind(&nts::P4008::computeInput, this, std::placeholders::_1);
  __mappute[2] = std::bind(&nts::P4008::computeInput, this, std::placeholders::_1);
  __mappute[3] = std::bind(&nts::P4008::computeInput, this, std::placeholders::_1);
  __mappute[4] = std::bind(&nts::P4008::computeInput, this, std::placeholders::_1);
  __mappute[5] = std::bind(&nts::P4008::computeInput, this, std::placeholders::_1);
  __mappute[6] = std::bind(&nts::P4008::computeInput, this, std::placeholders::_1);
  __mappute[7] = std::bind(&nts::P4008::computeInput, this, std::placeholders::_1);
  __mappute[15] = std::bind(&nts::P4008::computeInput, this, std::placeholders::_1);

  // carry in
  __mappute[9] = std::bind(&nts::P4008::computeInput, this, std::placeholders::_1);

  // out
  __mappute[10] = std::bind(&nts::P4008::computeOutput, this, std::placeholders::_1);
  __mappute[11] = std::bind(&nts::P4008::computeOutput, this, std::placeholders::_1);
  __mappute[12] = std::bind(&nts::P4008::computeOutput, this, std::placeholders::_1);
  __mappute[13] = std::bind(&nts::P4008::computeOutput, this, std::placeholders::_1);

  // carry out
  __mappute[14] = std::bind(&nts::P4008::computeCarryOut, this, std::placeholders::_1);

  // VDD
  __mappute[16] = std::bind(&nts::P4008::computeVDD, this, std::placeholders::_1);

  // VSS
  __mappute[8] = std::bind(&nts::P4008::computeVSS, this, std::placeholders::_1);

  __mapOutput[10] = std::make_pair(6, 7);
  __mapOutput[11] = std::make_pair(4, 5);
  __mapOutput[12] = std::make_pair(2, 3);
  __mapOutput[13] = std::make_pair(1, 15);
}

nts::P4008::~P4008(void) {}

nts::Tristate nts::P4008::Compute(size_t pute)
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

void nts::P4008::Setlien(size_t pute__num__this,
			 nts::IComponent &component,
			 size_t pute__num__target)
{
  if (pute__num__this - 1 < 16 && __pute[pute__num__this - 1] == NULL)
    {
      __lnk.insert(std::make_pair(pute__num__this - 1, pute__num__target));
      __pute[pute__num__this - 1] = &component;
      try {
	component.Setlien(pute__num__target, *this, pute__num__this);
      } catch (nts::ChipsetError const& e) {
	throw e;
      }
    }
  else if (pute__num__this - 1 > 15)
    throw nts::puteError(std::string("pute Exception: pute ")
			+ std::to_string(pute__num__this)
			+ std::string(" does not exist"));
}

void nts::P4008::Dump(void) const
{
  std::cout << "Chipset 4008" << std::endl;
  for (int i = 0 ; i < 16 ; i++)
    {
      std::cout << "\tpute #" << i + 1 << ": ";
      if (__pute[i])
	std::cout << __pute[i]->Compute(__lnk.at(i)) << std::endl;
      else
	std::cout << "NULL" << std::endl;
    }
}

nts::Tristate nts::P4008::compute__add(nts::Tristate lhs, nts::Tristate rhs,
				      nts::Tristate &carry) const
{
  char result = ((char)lhs) + ((char)rhs) + ((char)carry);
  carry = static_cast<nts::Tristate>(result >> 1);
  return (static_cast<nts::Tristate>(result & 1));
}

nts::Tristate nts::P4008::computeInput(size_t pute) const
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

nts::Tristate nts::P4008::computeOutput(size_t pute) const
{
  nts::Tristate result = nts::Tristate::UNDEFINED;
  nts::Tristate carry = nts::Tristate::FALSE;
  size_t lhs = 0;
  size_t rhs = 0;

  if (__mapOutput.find(pute) == __mapOutput.end())
    return (nts::Tristate::UNDEFINED);
  if (__pute[8])
    carry = __pute[8]->Compute(__lnk.at(8));
  for (size_t i = 10 ; i <= pute ; i++)
    if (__mapOutput.find(i) != __mapOutput.end())
      {
	lhs = __mapOutput.at(i).first;
	rhs = __mapOutput.at(i).second;
	if (__pute[lhs - 1] && __pute[rhs - 1])
	  result = compute__add(__pute[lhs - 1]->Compute(__lnk.at(lhs - 1)),
			       __pute[rhs - 1]->Compute(__lnk.at(rhs - 1)),
			       carry);
      }
  return (result);
}

nts::Tristate nts::P4008::computeCarryOut(size_t pute) const
{
  nts::Tristate carry = nts::Tristate::FALSE;
  size_t lhs = 0;
  size_t rhs = 0;

  if (__pute[8])
    carry = __pute[8]->Compute(__lnk.at(8));
  for (size_t i = 10 ; i < pute ; i++)
    if (__mapOutput.find(i) != __mapOutput.end())
      {
	lhs = __mapOutput.at(i).first;
	rhs = __mapOutput.at(i).second;
	if (__pute[lhs - 1] && __pute[rhs - 1])
	  compute__add(__pute[lhs - 1]->Compute(__lnk.at(lhs - 1)),
		      __pute[rhs - 1]->Compute(__lnk.at(rhs - 1)),
		      carry);
      }
  return (carry);
}

nts::Tristate nts::P4008::computeVDD(size_t pute) const
{
  (void)pute;
  std::cerr << "Warning: compute VDD result to UNDEFINED state" << std::endl;
  return (nts::Tristate::UNDEFINED);
}

nts::Tristate nts::P4008::computeVSS(size_t pute) const
{
  (void)pute;
  std::cerr << "Warning: compute VSS result to UNDEFINED state" << std::endl;
  return (nts::Tristate::UNDEFINED);
}
