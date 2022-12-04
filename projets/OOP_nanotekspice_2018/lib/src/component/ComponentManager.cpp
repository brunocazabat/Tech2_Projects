/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/

#include "ComponentManager.hpp"

nts::ComponentManager::ComponentManager(void)
{
  _ctor.insert(std::make_pair("input", std::bind(&nts::ComponentManager::createInput, this,
						 std::placeholders::_1)));
  _ctor.insert(std::make_pair("clock", std::bind(&nts::ComponentManager::createClock, this,
						 std::placeholders::_1)));
  _ctor.insert(std::make_pair("true", std::bind(&nts::ComponentManager::createTrue, this,
						 std::placeholders::_1)));
  _ctor.insert(std::make_pair("false", std::bind(&nts::ComponentManager::createFalse, this,
						 std::placeholders::_1)));
  _ctor.insert(std::make_pair("output", std::bind(&nts::ComponentManager::createOutput, this,
						  std::placeholders::_1)));
  _ctor.insert(std::make_pair("4001", std::bind(&nts::ComponentManager::create4001, this,
						std::placeholders::_1)));
  _ctor.insert(std::make_pair("4008", std::bind(&nts::ComponentManager::create4008, this,
						std::placeholders::_1)));
  _ctor.insert(std::make_pair("4011", std::bind(&nts::ComponentManager::create4011, this,
						std::placeholders::_1)));
  _ctor.insert(std::make_pair("4013", std::bind(&nts::ComponentManager::create4013, this,
						std::placeholders::_1)));
  _ctor.insert(std::make_pair("4017", std::bind(&nts::ComponentManager::create4017, this,
						std::placeholders::_1)));
  _ctor.insert(std::make_pair("4030", std::bind(&nts::ComponentManager::create4030, this,
						std::placeholders::_1)));
  _ctor.insert(std::make_pair("4040", std::bind(&nts::ComponentManager::create4040, this,
						std::placeholders::_1)));
  _ctor.insert(std::make_pair("4069", std::bind(&nts::ComponentManager::create4069, this,
						std::placeholders::_1)));
  _ctor.insert(std::make_pair("4071", std::bind(&nts::ComponentManager::create4071, this,
						std::placeholders::_1)));
  _ctor.insert(std::make_pair("4081", std::bind(&nts::ComponentManager::create4081, this,
						std::placeholders::_1)));
  _ctor.insert(std::make_pair("4094", std::bind(&nts::ComponentManager::create4094, this,
						std::placeholders::_1)));
  _ctor.insert(std::make_pair("4514", std::bind(&nts::ComponentManager::create4514, this,
						std::placeholders::_1)));
  _ctor.insert(std::make_pair("4801", std::bind(&nts::ComponentManager::create4801, this,
						std::placeholders::_1)));
  _ctor.insert(std::make_pair("2716", std::bind(&nts::ComponentManager::create2716, this,
						std::placeholders::_1)));
}

nts::ComponentManager::~ComponentManager(void)
{
  
}

nts::IComponent *nts::ComponentManager::createComponent(std::string const& type, std::string const& val)
{
  if (_ctor.find(type) == _ctor.end())
    return (NULL);
  return (_ctor[type](val));
}

nts::IComponent *nts::ComponentManager::createInput(const std::string &value) const
{
  return (new Input(value));
}

nts::IComponent *nts::ComponentManager::createClock(const std::string &value) const
{
  return (new Clock(value));
}

nts::IComponent *nts::ComponentManager::createTrue(const std::string &value) const
{
  (void)value;
  return (new True);
}

nts::IComponent *nts::ComponentManager::createFalse(const std::string &value) const
{
  (void)value;
  return (new False);
}

nts::IComponent *nts::ComponentManager::createOutput(const std::string &value) const
{
  (void)value;
  return (new Output);
}

nts::IComponent *nts::ComponentManager::create4001(const std::string &value) const
{
  return (new C4001(value));
}

nts::IComponent *nts::ComponentManager::create4008(const std::string &value) const
{
  return (new C4008(value));
}

nts::IComponent *nts::ComponentManager::create4011(const std::string &value) const
{
  return (new C4011(value));
}

nts::IComponent *nts::ComponentManager::create4013(const std::string &value) const
{
  return (new C4013(value));
}

nts::IComponent *nts::ComponentManager::create4017(const std::string &value) const
{
  return (new C4017(value));
}

nts::IComponent *nts::ComponentManager::create4030(const std::string &value) const
{
  return (new C4030(value));
}

nts::IComponent *nts::ComponentManager::create4040(const std::string &value) const
{
  return (new C4040(value));
}

nts::IComponent *nts::ComponentManager::create4069(const std::string &value) const
{
  return (new C4069(value));
}

nts::IComponent *nts::ComponentManager::create4071(const std::string &value) const
{
  return (new C4071(value));
}

nts::IComponent *nts::ComponentManager::create4081(const std::string &value) const
{
  return (new C4081(value));
}

nts::IComponent *nts::ComponentManager::create4094(const std::string &value) const
{
  return (new C4094(value));
}

nts::IComponent *nts::ComponentManager::create4514(const std::string &value) const
{
  return (new C4514(value));
}

nts::IComponent *nts::ComponentManager::create4801(const std::string &value) const
{
  return (new C4801(value));
}

nts::IComponent *nts::ComponentManager::create2716(const std::string &value) const
{
  return (new C2716(value));
}
