/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#pragma once

#include <iostream>
#include <ios>
#include <string>
#include "Keys.hpp"
#include "../../libs/src/IGraphicLib.hpp"
#include <chrono>
#include <map>
#include <fstream>

namespace Arcade {
	class PlayerScore {
	public:
		PlayerScore();
		bool setPlayerName(IGraphicLib &);
		std::string getPlayerName() const;
		bool writeScoreInFile();
		void setScore(int score);

	private:
		bool endescape(Keys curKey);
		std::string playerName;
		void addNewLetter(Keys);
		bool endEntry(Keys curKey);
		std::chrono::steady_clock::time_point timer;
		std::map<int, std::string> score;
		void openScore();
		int curScore;

	};
}
