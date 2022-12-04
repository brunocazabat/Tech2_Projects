/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#include <iostream>
#include "../include/LibNibbler.hpp"

Arcade::IGameLib *ret = nullptr;

__attribute__((constructor)) void enter()
{
	ret = new Arcade::LibNibbler;
}

__attribute__((destructor)) void out()
{
	delete ret;
}

extern "C" Arcade::IGameLib *entryPoint()
{
	return ret;
}
