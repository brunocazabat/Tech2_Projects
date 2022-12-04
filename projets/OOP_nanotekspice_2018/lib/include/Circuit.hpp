/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/

#ifndef _CIRCUIT_HPP_
#define _CIRCUIT_HPP_

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <utility>
#include "IComponent.hpp"
#include "IParser.hpp"
#include "ASTParser.hpp"

namespace nts
{
  class Circuit
  {
  public:
    Circuit(std::string const& filename,
	    std::vector<std::pair<std::string, std::string> > const& in);
    ~Circuit(void);
    
    void load(void);
    void displayOutput(void) const;
    void dump(void) const;
    void inverseClock(void) const;
    void updateInput(std::string const& name, std::string const& value);
  private:
    void deleteRoot(t_ast_node *root);

    std::string const _filename;
    ASTParser *_parser;
    t_ast_node *_root;
  };
}

#endif /* !_CIRCUIT_HPP_ */
