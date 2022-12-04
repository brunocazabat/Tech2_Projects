/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#pragma once

#include <string>
#include <vector>

namespace nts
{
  enum class ASTNodeType : int
  {
    DEFAULT = -1,
      NEWLINE = 0,
      SECTION,
      COMPONENT,
      lien,
      lien__END,
      STRING
      };
  
  typedef struct s__ast__node
  {
    s__ast__node(std::vector<struct s__ast__node *> *children) : children(children) {}
    std::string lexeme;
    ASTNodeType type;
    std::string val;
    std::vector<struct s__ast__node *> *children;
  } t__ast__node;
  
  class IParser
  {
  public:
    virtual ~IParser(void) {}
    virtual void feed(std::string const& input) = 0;
    virtual void parseTree(t__ast__node &root) = 0;
    virtual t__ast__node *createTree(void) = 0;
  };
}
