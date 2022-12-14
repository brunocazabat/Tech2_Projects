/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#include "../include/MenuManager.hpp"

Arcade::MenuManager::MenuManager()
{
	std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();
	this->timer = t1;
	this->cursPos.first = 0;
	this->cursPos.second = 0;
}

void Arcade::MenuManager::setLibPath(std::vector<std::string> &gameLib,
	std::vector<std::string> &graphLib)
{
	this->gameLib = gameLib;
	this->graphLib = graphLib;
}

std::string Arcade::MenuManager::printMenu(IGraphicLib &graphLib)
{
	Keys curKey = Keys::NONE;

	while (curKey != Keys::ESC) {
		Vect<size_t> size = graphLib.getScreenSize();
		while (graphLib.pollEvents()) {
			curKey = graphLib.getLastEvent();
			if (curKey == Keys::SPACE)
				return this->returnValue();
			this->moveCursos(curKey);
		}
		std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
		std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(
			t2 - this->timer);
		if (time_span.count() >= 0.2) {
			graphLib.clearWindow();
			this->printGraphLib(graphLib, size);
			this->printGameLib(graphLib, size);
			graphLib.refreshWindow();
			this->timer = t2;
		}
	}
	return "";
}

std::string Arcade::MenuManager::returnValue()
{
	if (this->cursPos.first == 0)
		return this->gameLib[this->cursPos.second];
	else
		return this->graphLib[this->cursPos.second];
	return "";
}

bool Arcade::MenuManager::canMoveDown()
{
	if (this->cursPos.first == 0) {
		if (this->cursPos.second < (int) this->gameLib.size() - 1)
			return true;
	} else {
		if (this->cursPos.second < (int) this->graphLib.size() - 1)
			return true;
	}
	return false;
}

void Arcade::MenuManager::moveCursos(Keys key)
{
	if (key == Z && this->cursPos.second > 0)
		this->cursPos.second--;
	else if (key == S && this->canMoveDown())
		this->cursPos.second++;
	else if (key == Q && this->cursPos.first > 0 &&
		this->cursPos.second < (int) this->gameLib.size())
		this->cursPos.first--;
	else if (key == D && this->cursPos.first < 1 &&
		this->cursPos.second < (int) this->graphLib.size())
		this->cursPos.first++;
}

void Arcade::MenuManager::printGraphLib(IGraphicLib &graphLib,
	Vect<size_t> size)
{
	size_t pos = 0;
	size_t inc = size.getY() / 25;
	int i = 0;

	Arcade::TextBox text("Librairies graphiques :", {size.getX() / 2, size.getY() / 10}, 25);
	graphLib.drawText(text);
	for (auto &elem: this->graphLib) {
		Arcade::TextBox text(elem.substr(elem.find('/') + 1),
			{size.getX() / 2, size.getY() / 6 + pos}, 25);
		if (this->cursPos.first == 1 && this->cursPos.second == i)
			text.setColor({255, 65, 65, 255});
		graphLib.drawText(text);
		pos += inc;
		i++;
	}
}

void Arcade::MenuManager::printGameLib(IGraphicLib &graphLib, Vect<size_t> size)
{
	size_t pos = 0;
	size_t inc = size.getY() / 25;
	int i = 0;
	Arcade::TextBox text("Jeux :", {15, size.getY() / 10}, 25);
	graphLib.drawText(text);
	for (auto &elem: this->gameLib) {
		Arcade::TextBox text(elem.substr(elem.find("/") + 1),
			{15, size.getY() / 6 + pos});
		if (this->cursPos.first == 0 && this->cursPos.second == i)
			text.setColor({255, 65, 65, 255});
		graphLib.drawText(text);
		pos += inc;
		i++;
	}
}