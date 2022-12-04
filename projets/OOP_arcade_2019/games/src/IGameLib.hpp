/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#pragma once

#include "../../libs/src/IGraphicLib.hpp"

namespace Arcade {
	class IGameLib {
	public:
		virtual ~IGameLib() = default;
		virtual const std::string getName() const = 0;
		virtual bool init() = 0;
		virtual bool stop() = 0;
		virtual void applyEvent(Keys key) = 0;
		virtual void update() = 0;
		virtual void refresh(IGraphicLib &graphicLib) = 0;
		virtual size_t getScore() = 0;
	};
};
