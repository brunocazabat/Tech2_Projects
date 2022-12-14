/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#pragma once

#include <queue>
#include <map>
#include <vector>
#include "../../IGraphicLib.hpp"
#include <SDL2/SDL_ttf.h>

namespace Arcade {
	class LibSDL : public IGraphicLib {
	public:
		LibSDL(Vect<size_t> screenSize, const std::string  &name);
		~LibSDL() override;
		std::string getName() const override;
		bool isOpen() const;
		void closeRenderer() override;
		void openRenderer(std::string const &title) override;
		void clearWindow() override;
		void refreshWindow() override;
		void drawPixelBox(PixelBox &);
		void drawPixel(int x, int y, const Color &color);
		void drawText(TextBox &);
		bool pollEvents() override;
		Keys getLastEvent() override;
		void clearEvents() override;
		Vect<size_t> getScreenSize() const override;
		size_t getMaxX() const override;
		size_t getMaxY() const override;

	private:
		std::queue<Arcade::Keys> events;
		Vect<size_t> screenSize;
		SDL_Renderer *renderer;
		SDL_Window *window;
	};
}