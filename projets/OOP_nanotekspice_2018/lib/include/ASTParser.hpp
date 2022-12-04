/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/

#ifndef _ASTPARSER_HPP_
#define _ASTPARSER_HPP_

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
  class ASTParser : public IParser
  {
  public:
    ASTParser(std::vector<std::pair<std::string, std::string> > const& in);
    virtual ~ASTParser(void);
    virtual void feed(std::string const& input);
    virtual void parseTree(t_ast_node &root);
    virtual t_ast_node *createTree(void);

    void setInValue(std::vector<std::pair<std::string, std::string> > const& in);
    void inverseClock(void) const;
    void displayOuput(void) const;
    void dump(void) const;
    void updateInput(std::string const& name, std::string const& value);
  private:
    std::vector<std::string> _input;
    std::string _current;
    std::unordered_map<std::string, std::string> _cache;
    std::unordered_map<std::string, std::string> _inputValue;
    std::unordered_map<std::string, IComponent *> _components;
    std::map<std::string, Output *> _ouputs;
    std::map<std::string, Input *> _inputs;
    std::map<std::string, True *> _trues;
    std::map<std::string, False *> _falses;
    std::map<std::string, Clock *> _clocks;
    
    t_ast_node *createNode(t_ast_node *root, std::string& token);
    ASTNodeType retrieveType(std::string const& token) const;
    std::string retrieveValue(std::string const& token) const;
    std::string retrieveName(std::string& token);
    
    std::vector<std::pair<std::function<bool(std::string const&)>,
			  std::function<ASTNodeType(void)> > > _typer;
    bool isSection(std::string const& token);
    bool isComponent(std::string const& token) const;
    bool isLink(std::string const& token) const;
    ASTNodeType putSection(void) const;
    ASTNodeType putComponent(void) const;
    ASTNodeType putLink(void) const;
    
    void createComponent(t_ast_node const& node);
    void createLink(t_ast_node const& node);

    bool isNum(std::string const& str);
  };
}

#endif /* !_ASTPARSER_HPP_ */
