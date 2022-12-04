/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#pragma once

#include <string>
#include <vector>

namespace Arcade {
	class ArgParser {
	public:
		ArgParser();
		~ArgParser() = default;

		static int parseArgs(int ac, char **av);
	};
}
