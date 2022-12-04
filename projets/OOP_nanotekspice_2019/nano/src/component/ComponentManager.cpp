/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#include "ComponentManager.hpp"

nts::ComponentManager::ComponentManager(void)
{
  __ctor.insert(std::make_pair("input", std::bind(&nts::ComponentManager::createInput, this, std::placeholders::_1)));
  __ctor.insert(std::make_pair("clock", std::bind(&nts::ComponentManager::createClock, this, std::placeholders::_1)));
  __ctor.insert(std::make_pair("true", std::bind(&nts::ComponentManager::createTrue, this, std::placeholders::_1)));
  __ctor.insert(std::make_pair("false", std::bind(&nts::ComponentManager::createFalse, this, std::placeholders::_1)));
  __ctor.insert(std::make_pair("output", std::bind(&nts::ComponentManager::createOutput, this, std::placeholders::_1)));
  __ctor.insert(std::make_pair("4001", std::bind(&nts::ComponentManager::create4001, this, std::placeholders::_1)));
  __ctor.insert(std::make_pair("4008", std::bind(&nts::ComponentManager::create4008, this, std::placeholders::_1)));
  __ctor.insert(std::make_pair("4011", std::bind(&nts::ComponentManager::create4011, this, std::placeholders::_1)));
  __ctor.insert(std::make_pair("4013", std::bind(&nts::ComponentManager::create4013, this, std::placeholders::_1)));
  __ctor.insert(std::make_pair("4017", std::bind(&nts::ComponentManager::create4017, this, std::placeholders::_1)));
  __ctor.insert(std::make_pair("4030", std::bind(&nts::ComponentManager::create4030, this, std::placeholders::_1)));
  __ctor.insert(std::make_pair("4040", std::bind(&nts::ComponentManager::create4040, this, std::placeholders::_1)));
  __ctor.insert(std::make_pair("4069", std::bind(&nts::ComponentManager::create4069, this, std::placeholders::_1)));
  __ctor.insert(std::make_pair("4071", std::bind(&nts::ComponentManager::create4071, this, std::placeholders::_1)));
  __ctor.insert(std::make_pair("4081", std::bind(&nts::ComponentManager::create4081, this, std::placeholders::_1)));
}

nts::ComponentManager::~ComponentManager(void) {}

nts::IComponent *nts::ComponentManager::createComponent(std::string const& type, std::string const& val)
{
  if (__ctor.find(type) == __ctor.end())
    return (NULL);
  return (__ctor[type](val));
}

nts::IComponent *nts::ComponentManager::createInput(const std::string &val) const
{
  return (new Input(val));
}

nts::IComponent *nts::ComponentManager::createClock(const std::string &val) const
{
  return (new Clock(val));
}

nts::IComponent *nts::ComponentManager::createTrue(const std::string &val) const
{
  (void)val;
  return (new True);
}

nts::IComponent *nts::ComponentManager::createFalse(const std::string &val) const
{
  (void)val;
  return (new False);
}

nts::IComponent *nts::ComponentManager::createOutput(const std::string &val) const
{
  (void)val;
  return (new Output);
}

nts::IComponent *nts::ComponentManager::create4001(const std::string &val) const
{
  return (new P4001(val));
}

nts::IComponent *nts::ComponentManager::create4008(const std::string &val) const
{
  return (new P4008(val));
}

nts::IComponent *nts::ComponentManager::create4011(const std::string &val) const
{
  return (new P4011(val));
}

nts::IComponent *nts::ComponentManager::create4013(const std::string &val) const
{
  return (new P4013(val));
}

nts::IComponent *nts::ComponentManager::create4017(const std::string &val) const
{
  return (new P4017(val));
}

nts::IComponent *nts::ComponentManager::create4030(const std::string &val) const
{
  return (new P4030(val));
}

nts::IComponent *nts::ComponentManager::create4040(const std::string &val) const
{
  return (new P4040(val));
}

nts::IComponent *nts::ComponentManager::create4069(const std::string &val) const
{
  return (new P4069(val));
}

nts::IComponent *nts::ComponentManager::create4071(const std::string &val) const
{
  return (new P4071(val));
}

nts::IComponent *nts::ComponentManager::create4081(const std::string &val) const
{
  return (new P4081(val));
}