/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/

#include "ASTParser.hpp"

nts::ASTParser::ASTParser(std::vector<std::pair<std::string, std::string> > const& in)
{
  _typer.push_back(std::make_pair(std::bind(&nts::ASTParser::isSection, this,
					    std::placeholders::_1),
				  std::bind(&nts::ASTParser::putSection, this)));
  _typer.push_back(std::make_pair(std::bind(&nts::ASTParser::isComponent, this,
					    std::placeholders::_1),
				  std::bind(&nts::ASTParser::putComponent, this)));
  _typer.push_back(std::make_pair(std::bind(&nts::ASTParser::isLink, this,
					    std::placeholders::_1),
				  std::bind(&nts::ASTParser::putLink, this)));
  setInValue(in);
}

nts::ASTParser::~ASTParser(void)
{
  for (auto it : _components)
    {
      delete it.second;
      it.second = NULL;
    }
}

void nts::ASTParser::updateInput(std::string const& name, std::string const& value)
{
  if (_inputs.find(name) == _inputs.end())
    {
      if (_clocks.find(name) != _clocks.end())
	throw nts::InputError("Error: '" + name + "' is a clock and can't be modified");
      else if (_ouputs.find(name) != _ouputs.end())
	throw nts::InputError("Error: '" + name + "' is an output and can't be modified");
      else if (_trues.find(name) != _trues.end())
	throw nts::InputError("Error: '" + name + "' is TRUE and can't be modified");
      else if (_falses.find(name) != _falses.end())
	throw nts::InputError("Error: '" + name + "' is FALSE and can't be modified");
      else
	throw nts::InputError("Error: '" + name + "' is undeclared");
    }
  try {
    _inputs[name]->setValue(value);
  } catch (nts::InputError const& e) {
    throw e;
  }
}

void nts::ASTParser::inverseClock(void) const
{
  if (_clocks.size() > 0)
    for (auto it : _clocks)
      it.second->inverseValue();
}

void nts::ASTParser::displayOuput(void) const
{
  if (_ouputs.size() > 0)
    for (auto it : _ouputs)
      std::cout << it.first << "=" << it.second->getValue() << std::endl;
}

void nts::ASTParser::dump(void) const
{
  if (_components.size())
    for (auto it : _components)
      {
	std::cout << it.first << ":" << std::endl;
	it.second->Dump();
      }
}

void nts::ASTParser::setInValue(std::vector<std::pair<std::string, std::string> > const& in)
{
  for (auto it : in)
    _inputValue[it.first] = it.second;  
}

void nts::ASTParser::feed(std::string const& input)
{
  std::string buffer = input;
  size_t pos_commentary = input.find_first_of("#");

  if (pos_commentary != std::string::npos)
    buffer = input.substr(0, pos_commentary);
  if (buffer.find_first_not_of(" \t") != std::string::npos)
    _input.push_back(buffer);
}

void nts::ASTParser::parseTree(t_ast_node &root)
{
  if (root.type == nts::ASTNodeType::COMPONENT)
    createComponent(root);
  else if (root.type == nts::ASTNodeType::LINK)
    createLink(root);
  if ((*root.children)[0])
    parseTree(*((*root.children)[0]));
  if(!(*root.children)[0])
    for (auto it : _ouputs)
      it.second->Compute();
}

nts::t_ast_node *nts::ASTParser::createTree(void)
{
  t_ast_node *root = NULL;

  for (auto it : _input)
    root = createNode(root, it);
  return (root);
}

nts::t_ast_node *nts::ASTParser::createNode(t_ast_node *root, std::string& token)
{
  if (root == NULL)
    {
      root = new t_ast_node(new std::vector<struct s_ast_node *>);
      root->children->push_back(NULL);
      root->value = retrieveValue(token);
      root->lexeme = retrieveName(token);
      root->type = retrieveType(token);
    }
  else
    {
      if ((*root->children)[0])
	createNode((*root->children)[0], token);
      else
	{
	  (*root->children)[0] = new t_ast_node(new std::vector<struct s_ast_node *>);
	  (*root->children)[0]->children->push_back(NULL);
	  (*root->children)[0]->value = retrieveValue(token);
	  (*root->children)[0]->lexeme = retrieveName(token);
	  (*root->children)[0]->type = retrieveType(token);
	}
    }
  return (root);
}

nts::ASTNodeType nts::ASTParser::retrieveType(std::string const& token) const
{
  std::string buffer = token;
  size_t pos = buffer.find_first_of(" \t");
  size_t i = 0;

  if (_current == ".chipsets:" && pos != std::string::npos)
    buffer = token.substr(0, pos);
  while (i < _typer.size() && !_typer[i].first(buffer))
    i++;
  if (i < _typer.size() && _typer[i].first(buffer))
    return (_typer[i].second());
  throw (nts::SyntaxError("Error: unrecognized symbol '" + buffer + "'"));
  return (nts::ASTNodeType::DEFAULT);
}

std::string nts::ASTParser::retrieveValue(std::string const& token) const
{
  std::string buffer;
  size_t pos = 0;
  size_t pos2 = 0;
  std::istringstream iss(token);
  std::vector<std::string> tokens;
  std::copy(std::istream_iterator<std::string>(iss),
	    std::istream_iterator<std::string>(),
	    std::back_inserter(tokens));
  if (tokens.size() == 2 && (tokens[0] == "input" || tokens[0] == "clock"))
    {
      buffer = tokens[1];
      pos = tokens[1].find_first_of("(");
      if (pos != std::string::npos)
	buffer = tokens[1].substr(0, pos);
      if (_inputValue.find(buffer) == _inputValue.end())
	throw nts::InputError("Error: '" + buffer + "' not initialized");
      return (_inputValue.at(buffer));
    }
  pos = token.find_first_of('(');
  if (pos == std::string::npos)
    return ("");
  pos2 = token.find_first_of(')', pos);
  if (pos2 == std::string::npos)
    throw (nts::SyntaxError("Error: missing ')' at '"  + token + "'"));
  return (token.substr(pos + 1, pos2 - pos - 1));
}

std::string nts::ASTParser::retrieveName(std::string& token)
{
  size_t pos = 0;
  std::istringstream iss(token);
  std::vector<std::string> tokens;
  std::copy(std::istream_iterator<std::string>(iss),
	    std::istream_iterator<std::string>(),
	    std::back_inserter(tokens));
  std::string buffer = "";
  for (size_t i = 0 ; i < tokens.size() ; i++)
    {
      buffer += tokens[i];
      if (i + 1 < tokens.size())
	buffer += " ";
    }
  pos = buffer.find_first_of("(");
  if (pos != std::string::npos)
    buffer = buffer.substr(0, pos);
  token = buffer;
  if (tokens.size() == 2 && _cache.find(tokens[1]) != _cache.end())
    throw nts::NtsError("Error: '" + tokens[1] + "' already declared");
  if (tokens.size() == 2 && isComponent(tokens[0]))
    _cache[tokens[1]] = tokens[0];
  return token;
}

bool nts::ASTParser::isSection(std::string const& token)
{
  bool test = (token == ".chipsets:" || token == ".links:");
  if (test)
    _current = token;
  return test;
}

bool nts::ASTParser::isComponent(std::string const& token) const
{
  nts::ComponentManager cmpt;
  IComponent *component = cmpt.createComponent(token, "");
  bool test = component != NULL;
  delete (component);
  return (test);
}

bool nts::ASTParser::isLink(std::string const& token) const
{
  size_t pos1 = 0;
  size_t pos2 = 0;
  std::istringstream iss(token);
  std::vector<std::string> tokens;
  std::copy(std::istream_iterator<std::string>(iss),
	    std::istream_iterator<std::string>(),
	    std::back_inserter(tokens));
  if (tokens.size() != 2)
    return (false);
  pos1 = tokens[0].find_first_of(":");
  pos2 = tokens[1].find_first_of(":");
  if (pos1 == std::string::npos || pos2 == std::string::npos)
    return (false);
  return (true);
}

nts::ASTNodeType nts::ASTParser::putSection(void) const
{
  return (nts::ASTNodeType::SECTION);
}

nts::ASTNodeType nts::ASTParser::putComponent(void) const
{
  return (nts::ASTNodeType::COMPONENT);
}

nts::ASTNodeType nts::ASTParser::putLink(void) const
{
  return (nts::ASTNodeType::LINK);
}

void nts::ASTParser::createComponent(t_ast_node const& node)
{
  nts::ComponentManager cmpt;
  std::istringstream iss(node.lexeme);
  std::vector<std::string> tokens;
  std::copy(std::istream_iterator<std::string>(iss),
	    std::istream_iterator<std::string>(),
	    std::back_inserter(tokens));
  if (tokens.size() == 2)
    {
      if (_components.find(tokens[1]) == _components.end())
	{
	  _components[tokens[1]] = cmpt.createComponent(tokens[0], node.value);
	  Output *out = dynamic_cast<Output *>(_components[tokens[1]]);
	  if (out != NULL)
	    _ouputs[tokens[1]] = out;
	  else
	    {
	      Clock *clock = dynamic_cast<Clock *>(_components[tokens[1]]);
	      if (clock != NULL)
		_clocks[tokens[1]] = clock;
	      else
		{
		  Input *in = dynamic_cast<Input *>(_components[tokens[1]]);
		  if (in != NULL)
		    _inputs[tokens[1]] = in;
		  else
		    {
		      True *t = dynamic_cast<True *>(_components[tokens[1]]);
		      if (t != NULL)
			_trues[tokens[1]] = t;
		      else
			{
			  False *f = dynamic_cast<False *>(_components[tokens[1]]);
			  if (f != NULL)
			    _falses[tokens[1]] = f;
			}
		    }
		}
	    }
	}
    }
}

void nts::ASTParser::createLink(t_ast_node const& node)
{
  size_t pos1 = 0;
  size_t pos2 = 0;
  std::string lhs_name;
  std::string rhs_name;
  std::string lhs_pinname;
  std::string rhs_pinname;
  size_t lhs_pin;
  size_t rhs_pin;
  nts::ComponentManager cmpt;
  std::istringstream iss(node.lexeme);
  std::vector<std::string> tokens;
  std::copy(std::istream_iterator<std::string>(iss),
	    std::istream_iterator<std::string>(),
	    std::back_inserter(tokens));
  if (tokens.size() == 2)
    {
      pos1 = tokens[0].find_first_of(":");
      pos2 = tokens[1].find_first_of(":");
      if (pos1 == std::string::npos || pos2 == std::string::npos)
	throw nts::SyntaxError("SyntaxError: " + node.lexeme + " must be lhs:pin rhs:pin");
      lhs_name = tokens[0].substr(0, pos1);
      rhs_name = tokens[1].substr(0, pos2);
      lhs_pinname = tokens[0].substr(pos1 + 1, tokens[0].size());
      rhs_pinname = tokens[1].substr(pos2 + 1, tokens[1].size());
      if (!isNum(lhs_pinname) || !isNum(rhs_pinname))
	throw (nts::SyntaxError("Syntax error: " + node.lexeme +
				": pin number must be integer value"));
      lhs_pin = std::stoi(lhs_pinname);
      rhs_pin = std::stoi(rhs_pinname);
      if (_components.find(lhs_name) == _components.end()
	  || _components.find(rhs_name) == _components.end())
	throw (nts::LinkError("LinkError: " + lhs_name + " undeclared"));
      _components[lhs_name]->SetLink(lhs_pin, *_components[rhs_name], rhs_pin);
    }
}

bool nts::ASTParser::isNum(std::string const& str)
{
  for (size_t i = 0 ; i < str.size() ; i++)
    if (!std::isdigit(str[i]))
      return (false);
  return (true);
}
