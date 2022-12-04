/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <utility>
#include "IComponent.hpp"
#include "IParser.hpp"
#include "Parser.hpp"

namespace nts
{
  class Circuit
  {
  public:
    Circuit(std::string const& filename, std::vector<std::pair<std::string, std::string> > const& in);
    ~Circuit(void);
    
    void load(void);
    void displayOutput(void) const;
    void dump(void) const;
    void inverseClock(void) const;
    void updateInput(std::string const& name, std::string const& val);
  private:
    void deleteRoot(t__ast__node *root);

    std::string const __filename;
    Parser *__parser;
    t__ast__node *__root;
  };
}