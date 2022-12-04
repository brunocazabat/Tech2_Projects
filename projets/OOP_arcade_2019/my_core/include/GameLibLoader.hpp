/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#pragma once

#include <string>
#include "../../games/src/IGameLib.hpp"

namespace Arcade {
	class GameLibLoader {
	public:
		GameLibLoader();
		~GameLibLoader();
		IGameLib *getLibInstance();
		bool loadLib(const std::string &libPath);
		bool unloadLib();

	private:
		std::string libPath;
		void *handleAddr;
		IGameLib *entryPointResult;
		bool isLibLoaded;
	};
}
