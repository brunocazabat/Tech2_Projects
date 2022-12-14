/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#pragma once

#include <queue>
#include <ncurses.h>
#include <map>
#include <list>
#include <sys/ioctl.h>
#include "../../IGraphicLib.hpp"

namespace Arcade {
	#define PERCENT(x) (x * 0.39)

	class LibNcurses : public IGraphicLib {
	public:
		LibNcurses(Vect<size_t> screenSize, const std::string &title);
		~LibNcurses() override;
		std::string getName() const override;
		bool isOpen() const override;
		void closeRenderer() override;
		void openRenderer(std::string const &title) override;
		void clearWindow() override;
		void refreshWindow() override;
		void drawPixelBox(PixelBox &) override;
		void drawPixel(int x, int y, char c, const Color &color);
		void init_ncurse_color(const Color &, const Color &, short &);
		void resetColor(short);
		void drawText(TextBox &) override;
		bool pollEvents() override;
		Keys getLastEvent() override;
		void clearEvents() override;
		Vect<size_t> getScreenSize() const override;
		size_t getMaxX() const override;
		size_t getMaxY() const override;

	private:
		std::queue<Arcade::Keys> events;
		Vect<size_t> screenSize;
		WINDOW *window;
		std::vector<std::pair<Arcade::Color, Arcade::Color>> colors;
		short translateColor(const Arcade::Color &color);
		short findInColors(const Color &c, const Color &bc);
	};
}