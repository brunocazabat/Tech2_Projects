/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/

#include <iostream>
#include <string>

#include "Exception.hpp"
#include "Nanotekspice.hpp"

int	main(int const ac, char const* const* const av)
{
  nts::Nanotekspice *nano = NULL;
  if (ac < 2)
    {
      std::cout << "Usage: file.nts [[input=value] [...]]" << std::endl;
      return (0);
    }
  try {
    nano = new nts::Nanotekspice(av[1], ac, av);
    nano->shell();
    delete (nano);
  } catch (nts::NtsError const& e) {
    std::cout << e.what() << std::endl;
  }
  return (0);
}
