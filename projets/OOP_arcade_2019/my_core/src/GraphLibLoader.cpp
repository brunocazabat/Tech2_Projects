/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#include <fstream>
#include <dlfcn.h>
#include <iostream>
#include <regex>
#include "../include/GraphLibLoader.hpp"

Arcade::GraphLibLoader::GraphLibLoader() : libPath(""), handleAddr(), entryPointResult(), isLibLoaded(false)
{
	this->handleAddr = nullptr;
	this->entryPointResult = nullptr;
}

Arcade::GraphLibLoader::~GraphLibLoader()
{
	this->unloadLib();
}

Arcade::IGraphicLib *Arcade::GraphLibLoader::getLibInstance()
{
	return this->entryPointResult;
}

bool Arcade::GraphLibLoader::loadLib(const std::string &libPath)
{
	std::string tmp;
	Arcade::IGraphicLib *(*val)() = nullptr;
	bool returnValue = false;

	if ((this->handleAddr = dlopen(libPath.c_str(), RTLD_LAZY))) {
		returnValue = true;
		*(void **) (&val) = dlsym(this->handleAddr, "entryPoint");
		if (val)
			this->entryPointResult = val();
		else
			returnValue = false;
	}
	else
		std::cout << dlerror() << std::endl;
	return returnValue;
}

bool Arcade::GraphLibLoader::unloadLib()
{
	if (this->handleAddr != nullptr)
		dlclose(this->handleAddr);
	this->handleAddr = nullptr;
	this->isLibLoaded = false;
	this->entryPointResult = nullptr;
	return true;
}
