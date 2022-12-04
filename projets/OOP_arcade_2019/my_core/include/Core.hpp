/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#pragma once

#include <string>
#include <vector>
#include <unistd.h>
#include "../../libs/src/IGraphicLib.hpp"
#include "../../games/src/IGameLib.hpp"
#include "PlayerScore.hpp"
#include "GameLibLoader.hpp"
#include "GraphLibLoader.hpp"
#include "MenuManager.hpp"
#include "ScoreManager.hpp"

namespace Arcade {
	class Core {
	public:
		explicit Core(const std::string &libPath);
		~Core();
		int startArcade();
		void parseLibDir();
		void parseGameDir();
		const GameLibLoader &getGameLoader() const;
		void setGameLoader(const GameLibLoader &gameLoader);
		const GraphLibLoader &getGraphLoader() const;
		void setGraphLoader(const GraphLibLoader &graphLoader);
		bool checkEvents(Arcade::Keys key);

	private:
		int arcadeLoop(Keys);
		bool initMenu();
		std::vector<std::string> libraryPathes;
		std::vector<std::string> gamePathes;
		std::string lauching_lib;
		GameLibLoader gameLoader;
		GraphLibLoader graphLoader;
		int selectedGame;
		int selectedLib;
		PlayerScore *playerName;
		IGraphicLib *graphlib;
		IGameLib *gameLib;
		MenuManager *menuManager;
		ScoreManager *scoreManager;
	};
}
