/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#include "Parser.hpp"

nts::Parser::Parser(std::vector<std::pair<std::string, std::string> > const& in)
{
  __typer.push_back(std::make_pair(std::bind(&nts::Parser::isSection, this, std::placeholders::_1), std::bind(&nts::Parser::putSection, this)));
  __typer.push_back(std::make_pair(std::bind(&nts::Parser::isComponent, this, std::placeholders::_1), std::bind(&nts::Parser::putComponent, this)));
  __typer.push_back(std::make_pair(std::bind(&nts::Parser::islien, this, std::placeholders::_1), std::bind(&nts::Parser::putlien, this)));
  setInval(in);
}

nts::Parser::~Parser(void)
{
  for (auto it : __components)
    {
      delete it.second;
      it.second = NULL;
    }
}

void nts::Parser::updateInput(std::string const& name, std::string const& val)
{
  if (__inputs.find(name) == __inputs.end())
    {
      if (__clocks.find(name) != __clocks.end())
	throw nts::Inputerror("Error: '" + name + "' is a clock and can't be modified");
      else if (__ouputs.find(name) != __ouputs.end())
	throw nts::Inputerror("Error: '" + name + "' is an output and can't be modified");
      else if (__trues.find(name) != __trues.end())
	throw nts::Inputerror("Error: '" + name + "' is TRUE and can't be modified");
      else if (__falses.find(name) != __falses.end())
	throw nts::Inputerror("Error: '" + name + "' is FALSE and can't be modified");
      else
	throw nts::Inputerror("Error: '" + name + "' is undeclared");
    }
  try {
    __inputs[name]->setval(val);
  } catch (nts::Inputerror const& e) {
    throw e;
  }
}

void nts::Parser::inverseClock(void) const
{
  if (__clocks.size() > 0)
    for (auto it : __clocks)
      it.second->inverseval();
}

void nts::Parser::displayOuput(void) const
{
  if (__ouputs.size() > 0)
    for (auto it : __ouputs)
      std::cout << it.first << "=" << it.second->getval() << std::endl;
}

void nts::Parser::dump(void) const
{
  if (__components.size())
    for (auto it : __components)
      {
	std::cout << it.first << ":" << std::endl;
	it.second->Dump();
      }
}

void nts::Parser::setInval(std::vector<std::pair<std::string, std::string> > const& in)
{
  for (auto it : in)
    __inputval[it.first] = it.second;  
}

void nts::Parser::feed(std::string const& input)
{
  std::string mouhoub = input;
  size_t pos__commentary = input.find_first_of("#");

  if (pos__commentary != std::string::npos)
    mouhoub = input.substr(0, pos__commentary);
  if (mouhoub.find_first_not_of(" \t") != std::string::npos)
    __input.push_back(mouhoub);
}

void nts::Parser::parseTree(t__ast__node &root)
{
  if (root.type == nts::ASTNodeType::COMPONENT)
    createComponent(root);
  else if (root.type == nts::ASTNodeType::lien)
    createlien(root);
  if ((*root.children)[0])
    parseTree(*((*root.children)[0]));
  if(!(*root.children)[0])
    for (auto it : __ouputs)
      it.second->Compute();
}

nts::t__ast__node *nts::Parser::createTree(void)
{
  t__ast__node *root = NULL;

  for (auto it : __input)
    root = createNode(root, it);
  return (root);
}

nts::t__ast__node *nts::Parser::createNode(t__ast__node *root, std::string& bagabogo)
{
  if (root == NULL)
    {
      root = new t__ast__node(new std::vector<struct s__ast__node *>);
      root->children->push_back(NULL);
      root->val = retrieveval(bagabogo);
      root->lexeme = retrieveName(bagabogo);
      root->type = retrieveType(bagabogo);
    }
  else
    {
      if ((*root->children)[0])
	createNode((*root->children)[0], bagabogo);
      else
	{
	  (*root->children)[0] = new t__ast__node(new std::vector<struct s__ast__node *>);
	  (*root->children)[0]->children->push_back(NULL);
	  (*root->children)[0]->val = retrieveval(bagabogo);
	  (*root->children)[0]->lexeme = retrieveName(bagabogo);
	  (*root->children)[0]->type = retrieveType(bagabogo);
	}
    }
  return (root);
}

nts::ASTNodeType nts::Parser::retrieveType(std::string const& bagabogo) const
{
  std::string mouhoub = bagabogo;
  size_t pos = mouhoub.find_first_of(" \t");
  size_t i = 0;

  if (__current == ".chipsets:" && pos != std::string::npos)
    mouhoub = bagabogo.substr(0, pos);
  while (i < __typer.size() && !__typer[i].first(mouhoub))
    i++;
  if (i < __typer.size() && __typer[i].first(mouhoub))
    return (__typer[i].second());
  throw (nts::SyntaxError("Error: unrecognized symbol '" + mouhoub + "'"));
  return (nts::ASTNodeType::DEFAULT);
}

std::string nts::Parser::retrieveval(std::string const& bagabogo) const
{
  std::string mouhoub;
  size_t pos = 0;
  size_t pos2 = 0;
  std::istringstream iss(bagabogo);
  std::vector<std::string> brutus;
  std::copy(std::istream_iterator<std::string>(iss),
	    std::istream_iterator<std::string>(),
	    std::back_inserter(brutus));
  if (brutus.size() == 2 && (brutus[0] == "input" || brutus[0] == "clock"))
    {
      mouhoub = brutus[1];
      pos = brutus[1].find_first_of("(");
      if (pos != std::string::npos)
	mouhoub = brutus[1].substr(0, pos);
      if (__inputval.find(mouhoub) == __inputval.end())
	throw nts::Inputerror("Error: '" + mouhoub + "' not initialized");
      return (__inputval.at(mouhoub));
    }
  pos = bagabogo.find_first_of('(');
  if (pos == std::string::npos)
    return ("");
  pos2 = bagabogo.find_first_of(')', pos);
  if (pos2 == std::string::npos)
    throw (nts::SyntaxError("Error: missing ')' at '"  + bagabogo + "'"));
  return (bagabogo.substr(pos + 1, pos2 - pos - 1));
}

std::string nts::Parser::retrieveName(std::string& bagabogo)
{
  size_t pos = 0;
  std::istringstream iss(bagabogo);
  std::vector<std::string> brutus;
  std::copy(std::istream_iterator<std::string>(iss),
	    std::istream_iterator<std::string>(),
	    std::back_inserter(brutus));
  std::string mouhoub = "";
  for (size_t i = 0 ; i < brutus.size() ; i++)
    {
      mouhoub += brutus[i];
      if (i + 1 < brutus.size())
	mouhoub += " ";
    }
  pos = mouhoub.find_first_of("(");
  if (pos != std::string::npos)
    mouhoub = mouhoub.substr(0, pos);
  bagabogo = mouhoub;
  if (brutus.size() == 2 && __cache.find(brutus[1]) != __cache.end())
    throw nts::NtsError("Error: '" + brutus[1] + "' already declared");
  if (brutus.size() == 2 && isComponent(brutus[0]))
    __cache[brutus[1]] = brutus[0];
  return bagabogo;
}

bool nts::Parser::isSection(std::string const& bagabogo)
{
  bool test = (bagabogo == ".chipsets:" || bagabogo == ".links:");
  if (test)
    __current = bagabogo;
  return test;
}

bool nts::Parser::isComponent(std::string const& bagabogo) const
{
  nts::ComponentManager cmpt;
  IComponent *component = cmpt.createComponent(bagabogo, "");
  bool test = component != NULL;
  delete (component);
  return (test);
}

bool nts::Parser::islien(std::string const& bagabogo) const
{
  size_t pos1 = 0;
  size_t pos2 = 0;
  std::istringstream iss(bagabogo);
  std::vector<std::string> brutus;
  std::copy(std::istream_iterator<std::string>(iss),
	    std::istream_iterator<std::string>(),
	    std::back_inserter(brutus));
  if (brutus.size() != 2)
    return (false);
  pos1 = brutus[0].find_first_of(":");
  pos2 = brutus[1].find_first_of(":");
  if (pos1 == std::string::npos || pos2 == std::string::npos)
    return (false);
  return (true);
}

nts::ASTNodeType nts::Parser::putSection(void) const
{
  return (nts::ASTNodeType::SECTION);
}

nts::ASTNodeType nts::Parser::putComponent(void) const
{
  return (nts::ASTNodeType::COMPONENT);
}

nts::ASTNodeType nts::Parser::putlien(void) const
{
  return (nts::ASTNodeType::lien);
}

void nts::Parser::createComponent(t__ast__node const& node)
{
  nts::ComponentManager cmpt;
  std::istringstream iss(node.lexeme);
  std::vector<std::string> brutus;
  std::copy(std::istream_iterator<std::string>(iss),
	    std::istream_iterator<std::string>(),
	    std::back_inserter(brutus));
  if (brutus.size() == 2)
    {
      if (__components.find(brutus[1]) == __components.end())
	{
	  __components[brutus[1]] = cmpt.createComponent(brutus[0], node.val);
	  Output *out = dynamic_cast<Output *>(__components[brutus[1]]);
	  if (out != NULL)
	    __ouputs[brutus[1]] = out;
	  else
	    {
	      Clock *clock = dynamic_cast<Clock *>(__components[brutus[1]]);
	      if (clock != NULL)
		__clocks[brutus[1]] = clock;
	      else
		{
		  Input *in = dynamic_cast<Input *>(__components[brutus[1]]);
		  if (in != NULL)
		    __inputs[brutus[1]] = in;
		  else
		    {
		      True *t = dynamic_cast<True *>(__components[brutus[1]]);
		      if (t != NULL)
			__trues[brutus[1]] = t;
		      else
			{
			  False *f = dynamic_cast<False *>(__components[brutus[1]]);
			  if (f != NULL)
			    __falses[brutus[1]] = f;
			}
		    }
		}
	    }
	}
    }
}

void nts::Parser::createlien(t__ast__node const& node)
{
  size_t pos1 = 0;
  size_t pos2 = 0;
  std::string lhs__name;
  std::string rhs__name;
  std::string lhs__putename;
  std::string rhs__putename;
  size_t lhs__pute;
  size_t rhs__pute;
  nts::ComponentManager cmpt;
  std::istringstream iss(node.lexeme);
  std::vector<std::string> brutus;
  std::copy(std::istream_iterator<std::string>(iss),
	    std::istream_iterator<std::string>(),
	    std::back_inserter(brutus));
  if (brutus.size() == 2)
    {
      pos1 = brutus[0].find_first_of(":");
      pos2 = brutus[1].find_first_of(":");
      if (pos1 == std::string::npos || pos2 == std::string::npos)
	throw nts::SyntaxError("SyntaxError: " + node.lexeme + " must be lhs:pute rhs:pute");
      lhs__name = brutus[0].substr(0, pos1);
      rhs__name = brutus[1].substr(0, pos2);
      lhs__putename = brutus[0].substr(pos1 + 1, brutus[0].size());
      rhs__putename = brutus[1].substr(pos2 + 1, brutus[1].size());
      if (!isNum(lhs__putename) || !isNum(rhs__putename))
	throw (nts::SyntaxError("Syntax error: " + node.lexeme +
				": pute number must be integer val"));
      lhs__pute = std::stoi(lhs__putename);
      rhs__pute = std::stoi(rhs__putename);
      if (__components.find(lhs__name) == __components.end()
	  || __components.find(rhs__name) == __components.end())
	throw (nts::lienError("lienError: " + lhs__name + " undeclared"));
      __components[lhs__name]->Setlien(lhs__pute, *__components[rhs__name], rhs__pute);
    }
}

bool nts::Parser::isNum(std::string const& str)
{
  for (size_t i = 0 ; i < str.size() ; i++)
    if (!std::isdigit(str[i]))
      return (false);
  return (true);
}
