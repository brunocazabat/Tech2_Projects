/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#pragma once

#include <queue>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "../../IGraphicLib.hpp"

namespace Arcade {
	class LibSFML : public IGraphicLib {
	public:
		LibSFML(Vect<size_t> screenSize, const std::string &title);
		~LibSFML() override;
		std::string getName() const override;
		bool isOpen() const override;
		void closeRenderer() override;
		void openRenderer(std::string const &title) override;
		void clearWindow() override;
		void refreshWindow() override;
		void drawPixelBox(PixelBox &) override;
		void drawText(TextBox &) override;
		bool pollEvents() override;
		Keys getLastEvent() override;
		void clearEvents() override;
		Vect<size_t> getScreenSize() const override;
		size_t getMaxX() const override;
		size_t getMaxY() const override;

	private:
		sf::Text text;
		std::queue<Arcade::Keys> events;
		Vect<size_t> screenSize;
		sf::RenderWindow window;
		sf::Texture texture;
		sf::Sprite sprite;
		sf::Font font;
	};
};