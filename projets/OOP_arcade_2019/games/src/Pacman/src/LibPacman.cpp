/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#include <ios>
#include <iostream>
#include <cstdlib>
#include <map>
#include <fcntl.h>
#include <zconf.h>
#include <thread>
#include <iomanip>
#include "../include/LibPacman.hpp"

static std::vector<std::string> PACMAN_MAP = {
	"   XXXXXXXXXXXXXXXXXXXXX   ",
	"   X.........X.........X   ",
	"   X.XXX.XXX.X.XXX.XXX.X   ",
	"   XoX X.X X.X.X X.X XoX   ",
	"   X.XXX.XXX.X.XXX.XXX.X   ",
	"   X...................X   ",
	"   X.XXX.X.XXXXX.X.XXX.X   ",
	"   X.XXX.X.XXXXX.X.XXX.X   ",
	"   X.....X...X...X.....X   ",
	"   X.XXX.XXX X XXX.XXX.X   ",
	"   X.XXX.X       X.XXX.X   ",
	"   X.XXX.X XX XX X.XXX.X   ",
	"   X.XXX.X X   X X.XXX.X   ",
	"   X.....  X   X  .....X   ",
	"   X.XXX.X XXXXX X.XXX.X   ",
	"   X.XXXoX       XoXXX.X   ",
	"   X.XXX.X XXXXX X.XXX.X   ",
	"   X.XXX.X XXXXX X.XXX.X   ",
	"   X.........X.........X   ",
	"   X.XXX.XXX.X.XXX.XXX.X   ",
	"   Xo..X..... .....X..oX   ",
	"   XXX.X.X.XXXXX.X.X.XXX   ",
	"   XXX.X.X.XXXXX.X.X.XXX   ",
	"   X.....X...X...X.....X   ",
	"   X.XXXXXXX.X.XXXXXXX.X   ",
	"   X...................X   ",
	"   XXXXXXXXXXXXXXXXXXXXX   "
};

static const std::map<Arcade::Keys, int> FIRST_ACTION = {
	{Arcade::Keys::Z, 0},
	{Arcade::Keys::S, 0},
	{Arcade::Keys::Q, -1},
	{Arcade::Keys::D, 1},
};

static const std::map<Arcade::Keys, int> SECOND_ACTION = {
	{Arcade::Keys::Z, -1},
	{Arcade::Keys::S, 1},
	{Arcade::Keys::Q, 0},
	{Arcade::Keys::D, 0},
};

static const std::vector<std::pair<int, int>> DIRECTION = {
	{0,  -1},
	{0,  1},
	{1,  0},
	{-1, 0},
};

static const std::vector<Arcade::Color> GHOSTS_COLORS = {
	{255, 184, 71,  255},
	{255, 0,   0,   255},
	{255, 184, 222, 255},
	{0,   255, 222, 255}
};

Arcade::LibPacman::LibPacman()
{
	std::vector<int> vect;
	for (int k = 0 ; k < MAP_WIDTH ; k++)
		vect.push_back(0);
	for (int i = 0 ; i < MAP_HEIGHT ; i++) {
		this->smellPassage.push_back(vect);
		this->smellValues.push_back(vect);
	}
	this->init();
	this->curKey = Keys::NONE;
	this->lastKey = Keys::Z;
	this->score = 0;
	this->msgScore = new TextBox("Score: " + std::to_string(this->score),
		{0, 0}, 25, {255, 255, 255, 255}, {255, 255, 255, 255});
	auto t1 = std::chrono::steady_clock::now();
	this->timeDisplay = t1;
	this->timer = t1;
	this->timeSleep = 0.6;
	this->lifes = 3;
	this->shouldStop = false;
	this->gCoords.emplace_back(12, 12);
	this->gCoords.emplace_back(12, 13);
	this->gCoords.emplace_back(14, 12);
	this->gCoords.emplace_back(14, 13);
	this->gStates.emplace_back(SLEEPING);
	this->gStates.emplace_back(SLEEPING);
	this->gStates.emplace_back(SLEEPING);
	this->gStates.emplace_back(SLEEPING);
	this->start = std::chrono::steady_clock::now();
}

Arcade::LibPacman::~LibPacman()
{
	delete this->msgScore;
}

const std::string Arcade::LibPacman::getName() const
{
	return "Nibbler";
}

bool Arcade::LibPacman::init()
{
	std::pair<int, int> pos;

	this->mapSize.setX(MAP_WIDTH);
	this->mapSize.setY(MAP_HEIGHT);

	this->pos.first = 13;
	this->pos.second = 20;
	return true;
}

bool Arcade::LibPacman::stop()
{
	return shouldStop;
}

void Arcade::LibPacman::applyEvent(Keys key)
{
	this->curKey = key;
}

void Arcade::LibPacman::update()
{
	auto t2 = std::chrono::steady_clock::now();
	auto timeSpan =
		std::chrono::duration_cast<std::chrono::duration<double>>(
			t2 - this->timer);
	if (timeSpan.count() <= this->timeSleep)
		return;
	if (curKey == Keys::NONE) {
		this->movePlayer(this->lastKey);
	} else {
		this->movePlayer(this->curKey);
		this->lastKey = this->curKey;
		this->curKey = Keys::NONE;
	}
	this->moveGhosts();
	this->timer = t2;
}

void Arcade::LibPacman::refresh(IGraphicLib &graphicLib)
{
	Vect<size_t> size = graphicLib.getScreenSize();
	if (size.getX() < size.getY()) {
		this->resize.setY(size.getX() / MAP_WIDTH);
		this->resize.setX(size.getX() / MAP_HEIGHT);
	} else {
		this->resize.setY(size.getY() / MAP_WIDTH);
		this->resize.setX(size.getY() / MAP_HEIGHT);
	}
	if (graphicLib.getName() == "Ncurses")
		this->resize.setY(this->resize.getY());
	this->msgScore->setPos({size.getY() / 40, size.getX() / 70});
	auto t2 = std::chrono::steady_clock::now();
	auto time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - this->timeDisplay);
	if (time_span.count() >= 0.1) {
		graphicLib.clearWindow();
		this->display(graphicLib);
		this->displaymap(graphicLib);
		graphicLib.drawText(*this->msgScore);
		graphicLib.refreshWindow();
		this->timeDisplay = t2;
	}
}

void Arcade::LibPacman::displaymap(IGraphicLib &graphicLib)
{
	char tmp;

	for (int j = 0 ; j < MAP_HEIGHT ; j++) {
		for (int i = 0 ; i < MAP_WIDTH ; i++) {
			tmp = PACMAN_MAP[j][i];
			if (tmp == 'X')
				this->drawRectangle(i, j, graphicLib,
					{0, 30, 255, 255}, false);
			else if (tmp == '.' || tmp == 'o')
				this->drawFood({i, j}, graphicLib,
					{255, 0, 255, 255}, tmp == '.');
		}
	}
}

void Arcade::LibPacman::display(IGraphicLib &graphicLib)
{
	this->drawRectangle(static_cast<size_t>(this->pos.first),
		static_cast<size_t>(this->pos.second),
		graphicLib, {0, 255, 0, 255},
		true);
	for (size_t i = 0 ; i < GHOSTS_COLORS.size() ; i++) {
		this->drawRectangle(
			static_cast<size_t>(this->gCoords[i].first),
			static_cast<size_t>(this->gCoords[i].second),
			graphicLib, GHOSTS_COLORS[i], true);
	}
}

void Arcade::LibPacman::drawRectangle(size_t x, size_t y,
	IGraphicLib &graphicLib,
	Color color, bool space)
{
	y = y * this->resize.getY();
	x = x * this->resize.getX();
	Arcade::PixelBox pixelBox({this->resize.getX(), this->resize.getY()},
		{x, y}, color);
	if (space && graphicLib.getName() != "Ncurses")
		pixelBox.setSize(
			{this->resize.getX() - 1, this->resize.getY() - 1});
	graphicLib.drawPixelBox(pixelBox);
}

void Arcade::LibPacman::drawFood(std::pair<size_t, size_t> pair,
	Arcade::IGraphicLib &graphicLib, Arcade::Color color, bool type)
{
	int size = type ? 4 : 2;
	int sizex = static_cast<int>(this->resize.getX() / size);
	int sizey = static_cast<int>(this->resize.getY() / size);

	pair.second = pair.second * this->resize.getY();
	pair.first = pair.first * this->resize.getX();
	if (graphicLib.getName() != "Ncurses") {
		pair.second += this->resize.getY() / 2 - sizey / 2;
		pair.first += this->resize.getX() / 2 - sizex / 2;
		Arcade::PixelBox pixelBox(
			{this->resize.getX() / size,
				this->resize.getY() / size},
			{pair.first, pair.second}, color);
		graphicLib.drawPixelBox(pixelBox);
	} else {
		TextBox food(type ? "." : "o", {pair.first, pair.second}, 1,
			{255, 0, 255, 255});
		graphicLib.drawText(food);
	}
}

void Arcade::LibPacman::movePlayer(Keys dir)
{
	std::pair<int, int> save = this->pos;
	char tmp;

	try {
		this->pos.first += FIRST_ACTION.at(dir);
		this->pos.second += SECOND_ACTION.at(dir);
	} catch (std::exception &e) {}
	tmp = PACMAN_MAP[this->pos.second][this->pos.first];
	if (tmp == 'X') {
		this->pos.first = save.first;
		this->pos.second = save.second;
	} else if (tmp == '.' || tmp == 'o') {
		this->score += tmp == '.' ? 1 : this->pacGum();
		PACMAN_MAP[this->pos.second][this->pos.first] = ' ';
		this->msgScore->setValue(
			"Score: " + std::to_string(this->score));
	}
	this->afterMovePlayer();
}

void Arcade::LibPacman::afterMovePlayer()
{
	if (this->checkEnd())
		this->shouldStop = true;
	this->resetDoubleVector(this->smellPassage);
	if (this->gStates[0] == RUNNING)
		this->spreadSmell(13, 13, 100);
	else
		this->spreadSmell(this->pos.first, this->pos.second, 100);
}

bool Arcade::LibPacman::checkEnd()
{
	bool ret = false;
	int count = 0;

	if (this->lifes == 0)
		return true;
	for (size_t k = 0 ; k < GHOSTS_COLORS.size() ; ++k) {
		if (this->gCoords[k].first == this->pos.first &&
			this->gCoords[k].second == this->pos.second &&
			this->gStates[k] != RUNNING)
			return true;
	}
	for (int j = 0 ; j < MAP_HEIGHT ; j++)
		for (int i = 0 ; i < MAP_WIDTH ; i++)
			if (PACMAN_MAP[j][i] == '.')
				count++;
	if (count == 0)
		ret = true;
	return ret;
}

size_t Arcade::LibPacman::getScore()
{
	return this->score;
}

void Arcade::LibPacman::showSmellValues()
{
	for (int i = 0 ; i < MAP_HEIGHT ; i++) {
		for (int j = 0 ; j < MAP_WIDTH ; ++j) {
			if (this->smellValues[i][j])
				std::cout << std::setw(3)
					<< this->smellValues[i][j];
			else
				std::cout << "   ";
		}
		std::cout << std::endl;
	}
}

void Arcade::LibPacman::moveGhosts()
{
	std::pair<int, int> save;

	for (size_t i = 0 ; i < this->gCoords.size() ; i++) {
		save.first = this->gCoords[i].first;
		save.second = this->gCoords[i].second;
		this->updateGhost(i);
		if (this->gStates[i] == SLEEPING)
			continue;
		auto save1 = this->determineDirection(this->gCoords[i].first,
			this->gCoords[i].second);
		this->gCoords[i].first += save1.first;
		this->gCoords[i].second += save1.second;
		for (size_t j = 0 ; j < GHOSTS_COLORS.size() ; j++) {
			if (j != i && (this->gCoords[j].first ==
				this->gCoords[i].first &&
				this->gCoords[j].second ==
					this->gCoords[i].second)) {
				this->gCoords[i].first = save.first;
				this->gCoords[i].second = save.second;
			}
		}
	}
}

void Arcade::LibPacman::updateGhost(int id)
{
	auto now = std::chrono::steady_clock::now();
	auto timeSpan =
		std::chrono::duration_cast<std::chrono::duration<double>>(
			now - this->start);
	auto timeMoment =
		std::chrono::duration_cast<std::chrono::duration<double>>(
			now - this->startMoment);
	if (this->gStates[id] == SLEEPING) {
		if (timeMoment.count() > 20)
			this->gStates[id] = CHASING;
	} else if (this->gStates[id] == RUNNING) {
		if (timeMoment.count() > 20) {
			this->gStates[id] = CHASING;
			this->start = std::chrono::steady_clock::now();
		}
	} else
		this->gStates[id] = CHASING;
	if (timeSpan.count() < id * 10)
		this->gStates[id] = SLEEPING;
	else if ((int)timeSpan.count() % 60 == 0)
		this->gStates[id] = SLEEPING;
}

std::pair<int, int> Arcade::LibPacman::determineDirection(int x, int y)
{
	std::vector<std::pair<std::pair<int, int>, int>> values = {
		{{1,  0},  this->smellValues[y][x + 1]},
		{{-1, 0},  this->smellValues[y][x - 1]},
		{{0,  1},  this->smellValues[y + 1][x]},
		{{0,  -1}, this->smellValues[y - 1][x]}
	};

	auto function = [](std::pair<std::pair<int, int>, int> a,
		std::pair<std::pair<int, int>, int> b) {
		return a.second >= b.second;
	};
	std::sort(values.begin(), values.end(), function);
	int i;
	char tmp;
	for (i = 0 ; i <= 3 ; i++) {
		tmp = PACMAN_MAP[y + values[i].first.second]
		[x + values[i].first.first];
		if (tmp != 'X' && (tmp < '1' || tmp > '4'))
			break;
	}
	return i >= 0 ? values[i].first : std::pair<int, int>(0, 0);
}

void Arcade::LibPacman::spreadSmell(int x, int y, int sv)
{
	this->smellPassage[y][x] = -1;
	this->smellValues[y][x] = sv;
	if (x + 1 < MAP_WIDTH && (this->smellPassage[y][x + 1] != -1 ||
		this->smellValues[y][x + 1] < sv) &&
		PACMAN_MAP[y][x + 1] != 'X')
		this->spreadSmell(x + 1, y, sv - 1);
	if (y - 1 > 0 && (this->smellPassage[y - 1][x] != -1 ||
		this->smellValues[y - 1][x] < sv) &&
		PACMAN_MAP[y - 1][x] != 'X')
		this->spreadSmell(x, y - 1, sv - 1);
	if (x - 1 > 0 && (this->smellPassage[y][x - 1] != -1 ||
		this->smellValues[y][x - 1] < sv) &&
		PACMAN_MAP[y][x - 1] != 'X')
		this->spreadSmell(x - 1, y, sv - 1);
	if (y + 1 < MAP_HEIGHT && (this->smellPassage[y + 1][x] != -1 ||
		this->smellValues[y + 1][x] < sv) &&
		PACMAN_MAP[y + 1][x] != 'X')
		this->spreadSmell(x, y + 1, sv - 1);
}

void
Arcade::LibPacman::resetDoubleVector(std::vector<std::vector<int>> &vector)
{
	for (int i = 0 ; i < MAP_HEIGHT ; i++)
		for (int j = 0 ; j < MAP_WIDTH ; j++)
			vector[i][j] = 0;
}

int Arcade::LibPacman::pacGum()
{
	this->startMoment = std::chrono::steady_clock::now();
	for (size_t i = 0 ; i < GHOSTS_COLORS.size() ; i++) {
		this->gStates[i] = RUNNING;
	}
	return 10;
}
