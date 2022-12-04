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
#include <ctime>
#include <thread>
#include <chrono>
#include <ctime>
#define MAP_WIDTH 27
#define MAP_HEIGHT 27

namespace Arcade {
	class LibPacman : public IGameLib {
	public:
		LibPacman();
		~LibPacman() override;
		const std::string getName() const override ;
		bool init() override ;
		bool stop() override ;
		void applyEvent(Keys key) override ;
		void update() override ;
		void refresh(IGraphicLib &graphicLib) override ;
		size_t getScore();
		static void displayMap(IGraphicLib *graphicLib);

	private:
		enum GHOSTSTATE {
			CHASING,
			RUNNING,
			SLEEPING
		};
		void display(IGraphicLib &graphicLib);
		void drawRectangle(size_t y, size_t x, IGraphicLib &graphicLib,
			Color color, bool space);
		void movePlayer(Keys dir);
		bool checkEnd();
		void displaymap(IGraphicLib &graphicLib);
		void drawFood(std::pair<size_t, size_t >, IGraphicLib &graphicLib, Color color, bool type);
		void moveGhosts();
		void updateGhost(int id);
		std::pair<int, int> determineDirection(int x, int y);
		void showSmellValues();
		void resetDoubleVector(std::vector<std::vector<int>> &vector);
		void spreadSmell(int x, int y, int sv);
		void afterMovePlayer();
		int pacGum();
		size_t score;
		Vect<size_t> mapSize;
		TextBox *msgScore;
		Vect<size_t>resize;
		Keys curKey;
		Keys lastKey;
		std::chrono::steady_clock::time_point timer;
		std::chrono::steady_clock::time_point timeDisplay;
		std::chrono::steady_clock::time_point start;
		std::chrono::steady_clock::time_point startMoment;
		double timeSleep;
		std::pair<int, int> pos;
		int lifes;
		bool shouldStop;
		std::vector<std::pair<int, int>> gCoords;
		std::vector<GHOSTSTATE> gStates;
		std::vector<std::vector<int>> smellValues;
		std::vector<std::vector<int>> smellPassage;
	};
};
