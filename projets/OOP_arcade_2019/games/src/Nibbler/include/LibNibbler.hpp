/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#pragma once

#include "../../IGameLib.hpp"
#include <algorithm>
#include <vector>
#include "time.h"
#include <thread>
#include <pthread.h>
#include <chrono>
#include <ctime>
#define MAP_WIDTH 29
#define MAP_HEIGHT 29

namespace Arcade {
	class LibNibbler : public IGameLib {
	public:
		LibNibbler();
		~LibNibbler() override;
		const std::string getName() const override ;
		bool init() override ;
		bool stop() override ;
		void applyEvent(Keys key) override ;
		void update() override ;
		void refresh(IGraphicLib &graphicLib) override ;
		size_t getScore();
		static void displayMap(IGraphicLib *graphicLib);

	private:
		size_t score;
		std::vector<std::pair<int, int>> playerPos;
		Vect<size_t> objectPos;
		Vect<size_t> mapSize;
		void setObjectPos();
		void display(IGraphicLib &graphicLib);
		void drawPlayer(size_t y, size_t x, IGraphicLib &graphicLib,  Color color, bool space);
		void movePlayer(Keys dir);
		int checkFood(Keys dir);
		void moveSnake();
		bool canGoBack(Keys key);
		bool checkEnd();
		bool checkSpawnPos();
		void displaymap(IGraphicLib &graphicLib);
		TextBox *msgScore;
		Vect<size_t>resize;
		Keys curKey;
		Keys lastKey;
		std::chrono::steady_clock::time_point timer;
		std::chrono::steady_clock::time_point timeDisplay;
		double timeSleep;
	};
};
