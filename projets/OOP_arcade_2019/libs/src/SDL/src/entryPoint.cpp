/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#include <iostream>
#include "../include/LibSDL.hpp"

Arcade::IGraphicLib *ret = nullptr;

__attribute__((constructor))
void enter()
{
	ret = new Arcade::LibSDL({800, 800}, "Arcade");
}

__attribute__((destructor))
void out()
{
	delete ret;
}

extern "C" Arcade::IGraphicLib *entryPoint()
{
	return ret;
}