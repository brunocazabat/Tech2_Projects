/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#include "../include/PlayerScore.hpp"
#include <unistd.h>

static const std::string INFOMSG= "Choisissez votre pseudo et appuyez sur espace pour valider.";

Arcade::PlayerScore::PlayerScore()
{
	std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();
	this->playerName.clear();
	this->timer = t1;
}

bool Arcade::PlayerScore::setPlayerName(IGraphicLib &graphLib)
{
	Keys curKey = Keys::NONE;
	Vect<size_t> size = graphLib.getScreenSize();
	Arcade::TextBox text("Nom ", {size.getX() / 3, size.getY() / 10}, 25);
	Arcade::TextBox info(INFOMSG, {50, size.getY() / 2}, 20);
	while (curKey != Keys::DOWN) {
		while (graphLib.pollEvents()) {
			curKey = graphLib.getLastEvent();
			if (endEntry(curKey))
				return true;
			if (!this->endescape(curKey))
				return false;
			this->addNewLetter(curKey);
		}
		text.setValue("Pseudo : " + this->playerName);
		std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
		std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - this->timer);
		if (time_span.count() >= 0.2) {
			graphLib.clearWindow();
			graphLib.drawText(text);
			graphLib.drawText(info);
			graphLib.refreshWindow();
			this->timer = t2;
		}
	}
	return true;
}

bool Arcade::PlayerScore::endescape(Keys curKey)
{
	if (curKey == Keys::ESC) {
		return false;
	}
	return true;
}

bool Arcade::PlayerScore::endEntry(Keys curKey)
{
	if (curKey == Keys::SPACE)
		return true;
	return false;
}

void Arcade::PlayerScore::addNewLetter(Keys curKey)
{
	char val;
	if (curKey == Keys::BACKSPACE)
		this->playerName = this->playerName.substr(0, this->playerName.size() - 1);
	else if (this->playerName.size() < 13){
		val = curKey + 96;
		if (val >= 96 && val <= 122)
			this->playerName += val;
	}
}

std::string Arcade::PlayerScore::getPlayerName() const
{
	return this->playerName;
}



void Arcade::PlayerScore::setScore(int score)
{
	this->curScore = score;
}