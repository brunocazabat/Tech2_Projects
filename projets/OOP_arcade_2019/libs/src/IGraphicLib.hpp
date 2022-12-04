/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#pragma once

#include <string>
#include "../../my_core/include/Vect.hpp"
#include "../../my_core/include/PixelBox.hpp"
#include "../../my_core/include/Color.hpp"
#include "../../my_core/include/TextBox.hpp"
#include "../../my_core/include/Keys.hpp"

namespace Arcade {
	class IGraphicLib {
	public:
		virtual ~IGraphicLib() = default;
		virtual std::string getName() const = 0;
		virtual bool isOpen() const = 0;
		virtual void closeRenderer() = 0;
		virtual void openRenderer(std::string const &title) = 0;
		virtual void clearWindow() = 0;
		virtual void refreshWindow() = 0;
		virtual void drawPixelBox(PixelBox &) = 0;
		virtual void drawText(TextBox &) = 0;
		virtual bool pollEvents() = 0;
		virtual Keys getLastEvent() = 0;
		virtual void clearEvents() = 0;
		virtual Vect<size_t> getScreenSize() const = 0;
		virtual size_t getMaxY() const = 0;
		virtual size_t getMaxX() const = 0;
	};
};
