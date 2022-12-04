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
#include "../include/GameLibLoader.hpp"

Arcade::GameLibLoader::GameLibLoader() : libPath(""), handleAddr(),
					   entryPointResult(), isLibLoaded(false)
{
	this->handleAddr = nullptr;
	this->entryPointResult = nullptr;
}

Arcade::GameLibLoader::~GameLibLoader()
{
	this->unloadLib();
}

Arcade::IGameLib *Arcade::GameLibLoader::getLibInstance()
{
	return this->entryPointResult;
}

bool Arcade::GameLibLoader::loadLib(const std::string &libPath)
{
	std::string tmp;
	Arcade::IGameLib *(*val)() = nullptr;
	bool returnValue = false;

	if ((this->handleAddr = dlopen(libPath.c_str(), RTLD_LAZY))) {
		returnValue = true;
		*(void **) (&val) = dlsym(this->handleAddr, "entryPoint");
		if (val)
			this->entryPointResult = val();
		else
			returnValue = false;
	}
	return returnValue;
}

bool Arcade::GameLibLoader::unloadLib()
{
	if (this->handleAddr != nullptr)
		dlclose(this->handleAddr);
	this->handleAddr = nullptr;
	this->isLibLoaded = false;
	this->entryPointResult = nullptr;
	return true;
}
