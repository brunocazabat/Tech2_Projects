/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <functional>
#include <utility>
#include <algorithm>
#include <iterator>
#include <sstream>
#include "IComponent.hpp"
#include "ComponentManager.hpp"
#include "IParser.hpp"
#include "Exception.hpp"
#include "Output.hpp"
#include "True.hpp"
#include "False.hpp"

namespace nts
{
  class Parser : public IParser
  {
  public:
    Parser(std::vector<std::pair<std::string, std::string> > const& in);
    virtual ~Parser(void);
    virtual void feed(std::string const& input);
    virtual void parseTree(t__ast__node &root);
    virtual t__ast__node *createTree(void);

    void setInval(std::vector<std::pair<std::string, std::string> > const& in);
    void inverseClock(void) const;
    void displayOuput(void) const;
    void dump(void) const;
    void updateInput(std::string const& name, std::string const& val);
  private:
    std::vector<std::string> __input;
    std::string __current;
    std::unordered_map<std::string, std::string> __cache;
    std::unordered_map<std::string, std::string> __inputval;
    std::unordered_map<std::string, IComponent *> __components;
    std::map<std::string, Output *> __ouputs;
    std::map<std::string, Input *> __inputs;
    std::map<std::string, True *> __trues;
    std::map<std::string, False *> __falses;
    std::map<std::string, Clock *> __clocks;
    
    t__ast__node *createNode(t__ast__node *root, std::string& token);
    ASTNodeType retrieveType(std::string const& token) const;
    std::string retrieveval(std::string const& token) const;
    std::string retrieveName(std::string& token);
    
    std::vector<std::pair<std::function<bool(std::string const&)>,
			  std::function<ASTNodeType(void)> > > __typer;
    bool isSection(std::string const& token);
    bool isComponent(std::string const& token) const;
    bool islien(std::string const& token) const;
    ASTNodeType putSection(void) const;
    ASTNodeType putComponent(void) const;
    ASTNodeType putlien(void) const;
    
    void createComponent(t__ast__node const& node);
    void createlien(t__ast__node const& node);

    bool isNum(std::string const& str);
  };
}
