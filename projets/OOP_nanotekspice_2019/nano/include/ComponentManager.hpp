/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#pragma once

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
#include "4001.hpp"
#include "4008.hpp"
#include "4011.hpp"
#include "4013.hpp"
#include "4017.hpp"
#include "4030.hpp"
#include "4040.hpp"
#include "4069.hpp"
#include "4071.hpp"
#include "4081.hpp"

namespace nts
{
  class ComponentManager
  {
  public:
    ComponentManager(void);
    ~ComponentManager(void);
    
    IComponent *createComponent(const std::string &type, const std::string &val);
  private:
    std::map<std::string, std::function<IComponent *(std::string const&)> > __ctor;
    
    IComponent *createInput(const std::string &val) const;
    IComponent *createClock(const std::string &val) const;
    IComponent *createOutput(const std::string &val) const;
    IComponent *createTrue(const std::string &val) const;
    IComponent *createFalse(const std::string &val) const;
    IComponent *create4001(const std::string &val) const;
    IComponent *create4008(const std::string &val) const;
    IComponent *create4011(const std::string &val) const;
    IComponent *create4013(const std::string &val) const;
    IComponent *create4017(const std::string &val) const;
    IComponent *create4030(const std::string &val) const;
    IComponent *create4040(const std::string &val) const;
    IComponent *create4069(const std::string &val) const;
    IComponent *create4071(const std::string &val) const;
    IComponent *create4081(const std::string &val) const;
  };
}