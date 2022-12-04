/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#pragma once

#include "../../libs/src/IGraphicLib.hpp"
#include <iostream>
#include <ios>
#include <chrono>
#include <fstream>
#include <map>
#include <regex>

namespace Arcade {
	class ScoreManager {
	public:
		ScoreManager();
		void printScore(IGraphicLib &graphLib);

	private:
		void printPlayers(IGraphicLib &graphLib);
		std::chrono::steady_clock::time_point timer;
		std::map<int, std::string> score;
	};
}