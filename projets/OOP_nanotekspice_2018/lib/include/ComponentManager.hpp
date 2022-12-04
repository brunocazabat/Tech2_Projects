/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/

#ifndef _COMPONENTMANAGER_HPP_
#define _COMPONENTMANAGER_HPP_
#include <string>
#include <utility>
#include <iostream>
#include <map>
#include <functional>
#include "IComponent.hpp"
#include "Input.hpp"
#include "True.hpp"
#include "False.hpp"
#include "Clock.hpp"
#include "Output.hpp"
#include "C4001.hpp"
#include "C4008.hpp"
#include "C4011.hpp"
#include "C4013.hpp"
#include "C4017.hpp"
#include "C4030.hpp"
#include "C4040.hpp"
#include "C4069.hpp"
#include "C4071.hpp"
#include "C4081.hpp"
#include "C4094.hpp"
#include "C4514.hpp"
#include "C4801.hpp"
#include "C2716.hpp"

namespace nts
{
  class ComponentManager
  {
  public:
    ComponentManager(void);
    ~ComponentManager(void);
    
    IComponent *createComponent(const std::string &type, const std::string &value);
  private:
    std::map<std::string, std::function<IComponent *(std::string const&)> > _ctor;
    
    IComponent *createInput(const std::string &value) const;
    IComponent *createClock(const std::string &value) const;
    IComponent *createOutput(const std::string &value) const;
    IComponent *createTrue(const std::string &value) const;
    IComponent *createFalse(const std::string &value) const;
    IComponent *create4001(const std::string &value) const;
    IComponent *create4008(const std::string &value) const;
    IComponent *create4011(const std::string &value) const;
    IComponent *create4013(const std::string &value) const;
    IComponent *create4017(const std::string &value) const;
    IComponent *create4030(const std::string &value) const;
    IComponent *create4040(const std::string &value) const;
    IComponent *create4069(const std::string &value) const;
    IComponent *create4071(const std::string &value) const;
    IComponent *create4081(const std::string &value) const;
    IComponent *create4094(const std::string &value) const;
    IComponent *create4514(const std::string &value) const;
    IComponent *create4801(const std::string &value) const;
    IComponent *create2716(const std::string &value) const;
  };
}

#endif /* !_COMPONENTMANAGER_HPP_ */
