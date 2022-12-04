/*
** EPITECH PROJECT, 2018
** cpp_arcade
** File description:
** entryPoint.cpp
*/

#include <iostream>
#include "../include/LibPacman.hpp"

Arcade::IGameLib *ret = nullptr;
__attribute__((constructor)) void enter()
{
	ret = new Arcade::LibPacman;
}

__attribute__((destructor)) void out()
{
	delete ret;
}

extern "C" Arcade::IGameLib *entryPoint()
{
	return ret;
}
