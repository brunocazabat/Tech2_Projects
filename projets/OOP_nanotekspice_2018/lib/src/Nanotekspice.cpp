/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/

#include "Nanotekspice.hpp"

bool nts::Nanotekspice::Loop = false;
std::string nts::Nanotekspice::Prompt = "> ";

nts::Nanotekspice::Nanotekspice(std::string const& filename, int const ac, char const * const * const av) : _ac(ac)
{
  size_t pos = 0;
  _isrunning = true;
  for (int i = 2 ; i < ac ; i++)
    {
      std::string buff(av[i]);
      pos = buff.find_first_of("=");
      if (pos != std::string::npos)
	{
	  std::string tmp = buff.substr(pos + 1, buff.size());
	  if (tmp != "0" && tmp != "1")
	    throw (nts::InputError("InputError: Input value must be e. to 0 or 1"));
	  _av.push_back(std::make_pair(buff.substr(0, pos), tmp));
	}
    }
  _cmd["exit"] = std::bind(&nts::Nanotekspice::exit, this);
  _cmd["display"] = std::bind(&nts::Nanotekspice::display, this);
  _cmd["simulate"] = std::bind(&nts::Nanotekspice::simulate, this);
  _cmd["loop"] = std::bind(&nts::Nanotekspice::loop, this);
  _cmd["dump"] = std::bind(&nts::Nanotekspice::dump, this);

  try {
    _circuit = new nts::Circuit(filename, _av);
  } catch (nts::NtsError const& e) {
    throw (e);
  }
}

nts::Nanotekspice::~Nanotekspice(void)
{
  delete _circuit;
}

void nts::Nanotekspice::shell(void)
{
  std::string buffer = "";
  size_t pos = 0;

  signal(SIGINT, doNothing);  
  try {
    simulate();
    display();
  } catch (nts::NtsError const& e) {
    throw (e);
  }
  std::cout << nts::Nanotekspice::Prompt;
  while (_isrunning && std::getline(std::cin, buffer))
    {
      buffer = epurcmd(buffer);
      if (_cmd.find(buffer) != _cmd.end())
	_cmd[buffer]();
      else
	{
	  pos = buffer.find_first_of("=");
	  if (pos != std::string::npos)
	    setInputValue(buffer, pos);
	  else if (buffer.size() > 0)
	    std::cout << "'" << buffer << "': unknown command" << std::endl;
	}
      if (_isrunning)
	std::cout << nts::Nanotekspice::Prompt;
    }
}

void nts::Nanotekspice::exit(void)
{
  _isrunning = false;
}

void nts::Nanotekspice::display(void)
{
  if (_circuit != NULL)
    _circuit->displayOutput();
}

void nts::Nanotekspice::simulate(void)
{
  try {
    if (_circuit != NULL)
      {
	_circuit->load();
	_circuit->inverseClock();
      }
  } catch (nts::NtsError const& e) {
    throw e;
  }
}

void nts::Nanotekspice::loop(void)
{
  nts::Nanotekspice::Loop = true;
  signal(SIGINT, signalLoop);
  while (nts::Nanotekspice::Loop)
    {
      simulate();
    }
  signal(SIGINT, doNothing);
}

void nts::Nanotekspice::dump(void)
{
  if (_circuit != NULL)
    _circuit->dump();
}

void nts::Nanotekspice::setInputValue(std::string const& s, size_t const pos) const
{
  std::string lhs;
  std::string rhs;

  lhs = s.substr(0, pos);
  rhs = s.substr(pos + 1, s.size());
  try {
    if (_circuit != NULL)
      _circuit->updateInput(lhs, rhs);
  } catch (nts::NtsError const& e) {
    std::cout << e.what() << std::endl;
  }
}

std::string nts::Nanotekspice::epurcmd(std::string const& cmd) const
{
  std::string epur = "";
  std::istringstream iss(cmd);
  std::vector<std::string> tokens;
  std::copy(std::istream_iterator<std::string>(iss), std::istream_iterator<std::string>(), std::back_inserter(tokens));
  
  for (size_t i = 0 ; i < tokens.size() ; i++)
    {
      epur += tokens[i];
      if (i + 1 < tokens.size())
	epur += " ";
    }
  return epur;
}

void signalLoop(int n)
{
    (void)n;
    nts::Nanotekspice::Loop = false;
}

void doNothing(int n)
{
    (void)n;
}
