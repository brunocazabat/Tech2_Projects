/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#include <iostream>
#include <fstream>
#include "../include/ArgParser.hpp"

Arcade::ArgParser::ArgParser() = default;

int Arcade::ArgParser::parseArgs(int ac, char **av)
{
	std::string path;
	int val = 0;

	if (ac != 2)
		return 84;
	path = av[1];
	std::ifstream bruh(path);
	if (bruh.fail())
		val = 84;
	return val;
}
