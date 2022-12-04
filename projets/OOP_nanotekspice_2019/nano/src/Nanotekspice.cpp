/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#include "Nanotekspice.hpp"

bool nts::Nanotekspice::Loop = false;
std::string nts::Nanotekspice::Prompt = "> ";

nts::Nanotekspice::Nanotekspice(std::string const& filename, int const ac, char const * const * const av) : __ac(ac)
{
  size_t pos = 0;
  __isrunning = true;
  for (int i = 2 ; i < ac ; i++)
    {
      std::string buff(av[i]);
      pos = buff.find_first_of("=");
      if (pos != std::string::npos)
	{
	  std::string tmp = buff.substr(pos + 1, buff.size());
	  if (tmp != "0" && tmp != "1")
	    throw (nts::Inputerror("Inputerror: Input val must be e. to 0 or 1"));
	  __av.push_back(std::make_pair(buff.substr(0, pos), tmp));
	}
    }
  __cmd["exit"] = std::bind(&nts::Nanotekspice::exit, this);
  __cmd["display"] = std::bind(&nts::Nanotekspice::display, this);
  __cmd["simulate"] = std::bind(&nts::Nanotekspice::simulate, this);
  __cmd["loop"] = std::bind(&nts::Nanotekspice::loop, this);
  __cmd["dump"] = std::bind(&nts::Nanotekspice::dump, this);

  try {
    __circuit = new nts::Circuit(filename, __av);
  } catch (nts::NtsError const& e) {
    throw (e);
  }
}

nts::Nanotekspice::~Nanotekspice(void)
{
  delete __circuit;
}

void nts::Nanotekspice::shell(void)
{
  std::string mouhoub = "";
  size_t pos = 0;

  signal(SIGINT, doNothing);  
  try {
    simulate();
    display();
  } catch (nts::NtsError const& e) {
    throw (e);
  }
  std::cout << nts::Nanotekspice::Prompt;
  while (__isrunning && std::getline(std::cin, mouhoub))
    {
      mouhoub = epurcmd(mouhoub);
      if (__cmd.find(mouhoub) != __cmd.end())
	__cmd[mouhoub]();
      else
	{
	  pos = mouhoub.find_first_of("=");
	  if (pos != std::string::npos)
	    setInputval(mouhoub, pos);
	  else if (mouhoub.size() > 0)
	    std::cout << "'" << mouhoub << "': unknown command" << std::endl;
	}
      if (__isrunning)
	std::cout << nts::Nanotekspice::Prompt;
    }
}

void nts::Nanotekspice::exit(void)
{
  __isrunning = false;
}

void nts::Nanotekspice::display(void)
{
  if (__circuit != NULL)
    __circuit->displayOutput();
}

void nts::Nanotekspice::simulate(void)
{
  try {
    if (__circuit != NULL)
      {
	__circuit->load();
	__circuit->inverseClock();
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
  if (__circuit != NULL)
    __circuit->dump();
}

void nts::Nanotekspice::setInputval(std::string const& s, size_t const pos) const
{
  std::string lhs;
  std::string rhs;

  lhs = s.substr(0, pos);
  rhs = s.substr(pos + 1, s.size());
  try {
    if (__circuit != NULL)
      __circuit->updateInput(lhs, rhs);
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
