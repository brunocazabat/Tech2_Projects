/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#pragma once

#include <string>
#include "../../libs/src/IGraphicLib.hpp"

namespace Arcade {
	class GraphLibLoader {
	public:
		GraphLibLoader();
		~GraphLibLoader();
		IGraphicLib *getLibInstance();
		bool loadLib(const std::string &libPath);
		bool unloadLib();

	private:
		std::string libPath;
		void *handleAddr;
		IGraphicLib *entryPointResult;
		bool isLibLoaded;
	};
}
